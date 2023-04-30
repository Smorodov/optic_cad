/*

      This file is part of the <goptical/core Core library.

      The <goptical/core library is free software; you can redistribute it
      and/or modify it under the terms of the GNU General Public
      License as published by the Free Software Foundation; either
      version 3 of the License, or (at your option) any later version.

      The <goptical/core library is distributed in the hope that it will be
      useful, but WITHOUT ANY WARRANTY; without even the implied
      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
      See the GNU General Public License for more details.

      You should have received a copy of the GNU General Public
      License along with the <goptical/core library; if not, write to the
      Free Software Foundation, Inc., 59 Temple Place, Suite 330,
      Boston, MA 02111-1307 USA

      Copyright (C) 2010-2011 Free Software Foundation, Inc
      Author: Alexandre Becoulet

*/

#include <goptical/core/common.hpp>
#include <goptical/core/sys/container.hpp>
#include <goptical/core/sys/group.hpp>
#include <goptical/core/sys/system.hpp>

#include <goptical/core/error.hpp>
#include <goptical/core/material/air.hpp>
#include <goptical/core/material/proxy.hpp>
#include <goptical/core/math/transform.hpp>
#include <goptical/core/sys/optical_surface.hpp>
#include <goptical/core/sys/source.hpp>
#include <goptical/core/sys/surface.hpp>
#include <goptical/core/trace/params.hpp>
#include <goptical/core/trace/ray.hpp>

namespace goptical
{

	namespace sys
	{

		System::System ()
			: _version (0), _env_proxy (material::std_air), _tracer_params (),
			  _e_count (0), _index_map (), _transform_cache ()
		{
			transform_cache_resize (1);
			// index 0 is reserved for global coordinates transformations
			_index_map[0] = (Element *)1;
		}

		System::~System ()
		{
			// remove_all();
			transform_cache_flush ();
		}

		void
		System::add (std::shared_ptr<Element> e)
		{
			if (e->_system)
			{
				throw Error ("Element already added to a system");
			}
			Container::add (e);
			e->system_register (this);
		}

		void
		System::set_environment (const std::shared_ptr<material::Base> &env)
		{
			update_version ();
			material::Base *base = _env_proxy.get ();
			material::Proxy *proxy = dynamic_cast<material::Proxy *> (base);
			if (!proxy)
			{
				throw Error ("Unexpected type in proxy");
			}
			proxy->set_material (env);
		}

		const math::Transform<3> &
		System::transform_l2g_cache_update (const Element &element) const
		{
			math::Transform<3> *&e = transform_cache_entry (element.id (), 0);
			if (!e)
			{
				math::Transform<3> t (element._transform);
				const Element *i1 = &element;
				// FIXME why while?
				while (const Element *i2 = i1->_group)
				{
					t.compose (i2->_transform);
					i1 = i2;
				}
				assert (!e);
				e = new math::Transform<3> (t);
			}
			return *e;
		}

		const math::Transform<3> &
		System::transform_g2l_cache_update (const Element &element) const
		{
			math::Transform<3> *&e = transform_cache_entry (0, element.id ());
			if (!e)
				e = new math::Transform<3> (
				    transform_l2g_cache_update (element).inverse ());
			return *e;
		}

		const math::Transform<3> &
		System::transform_cache_update (const Element &from, const Element &to) const
		{
			assert (&from != &to);
			math::Transform<3> *&e = transform_cache_entry (from.id (), to.id ());
			if (!e)
			{
				const math::Transform<3> &t1 = transform_l2g_cache_update (from);
				const math::Transform<3> &t2 = transform_l2g_cache_update (to);
				if (!e)
				{
					e = new math::Transform<3> (t1);
					e->compose (t2.inverse ());
				}
			}
			return *e;
		}

		void
		System::transform_cache_delete (unsigned int from, unsigned int to)
		{
			auto offset = from * _e_count + to;
			if (_transform_cache[offset])
			{
				delete _transform_cache[offset];
				_transform_cache[offset] = nullptr;
			}
		}

		void
		System::transform_cache_flush (const Element &element)
		{
			for (unsigned int x = 0; x < _e_count; x++)
			{
				transform_cache_delete (element.id (), x);
				transform_cache_delete (x, element.id ());
			}
		}

		void
		System::transform_cache_flush ()
		{
			for (unsigned int x = 0; x < _e_count; x++)
				for (unsigned int y = 0; y < _e_count; y++)
				{
					transform_cache_delete (x, y);
				}
		}

		void
		System::transform_cache_resize (unsigned int newsize)
		{
			unsigned int oldsize = _e_count;
			if (oldsize < newsize)
			{
				_index_map.resize (newsize, 0);
				_transform_cache.resize (newsize * newsize, 0);
				for (int y = oldsize - 1; y > 0; y--)
				{
					// move data
					for (int x = oldsize - 1; x >= 0; x--)
					{
						_transform_cache[y * newsize + x]
						    = _transform_cache[y * oldsize + x];
						_transform_cache[y * oldsize + x] = nullptr;
					}
				}
				_e_count = newsize;
			}
			else
			{
				// FIXME handle cache downsize
			}
		}

		unsigned int
		System::index_get (Element &element)
		{
			for (unsigned int i = 0; i < _index_map.size (); i++)
			{
				if (_index_map[i] == nullptr)
				{
					_index_map[i] = &element;
					// fprintf(stderr, "Re-Assigned %u to element %p\n", i, &element);
					return i;
				}
			}
			unsigned int index = _e_count;
			transform_cache_resize (index + 1);
			assert (index + 1 == _index_map.size ());
			_index_map[index] = &element;
			// fprintf(stderr, "Assigned %u to element %p\n", index, &element);
			return index;
		}

		void
		System::index_put (const Element &element)
		{
			transform_cache_flush (element);
			assert (element.id () < _index_map.size ());
			_index_map[element.id ()] = nullptr;
			// fprintf(stderr, "Freed %u previously assigned to element %p\n",
			// element.id(), &element);
		}

		void
		System::transform_cache_dump (std::ostream &o) const
		{
			o << "system transform cache size is " << _e_count << "x" << _e_count
			  << std::endl;
			for (unsigned int from = 0; from < _e_count; from++)
				for (unsigned int to = 0; to < _e_count; to++)
					if (const math::Transform<3> *t = _transform_cache[from * _e_count + to])
						o << "from " << from << " to " << to << ":" << std::endl
						  << *t << std::endl;
		}

		const Surface &
		System::get_entrance_pupil () const
		{
			const Surface *res = 0;
			if (_entrance)
			{
				return *_entrance;
			}
			res = find<OpticalSurface> ();
			if (!res)
			{
				res = find<Surface> ();
			}
			if (!res)
			{
				throw Error ("No entrance pupil surface defined/guessed");
			}
			return *res;
		}

		/** FIXME write an optimized version of this function which uses
		    some kind of data structure (bsp tree?) */
		Surface *
		System::colide_next (const trace::Params &params, math::VectorPair3 &intersect,
		                     const trace::Ray &ray) const
		{
			const Element *origin = ray.get_creator ();
			// test all elements and keep closest intersection
			Surface *s, *e = 0;
			math::VectorPair3 inter;
			double min_dist = std::numeric_limits<double>::max ();
			for (unsigned int i = 1; i <= get_element_count (); i++)
			{
				Element *j = &get_element (i);
				if (j == origin || !j->is_enabled ())
				{
					continue;
				}
				if ((s = dynamic_cast<Surface *> (j)))
				{
					const math::Transform<3> &t = origin->get_transform_to (*s);
					math::VectorPair3 local (t.transform_line (ray));
					if (s->intersect (params, inter, local))
					{
						double dist = (inter.origin () - local.origin ()).len ();
						if (min_dist > dist)
						{
							min_dist = dist;
							intersect = inter;
							e = s;
						}
					}
				}
			}
			return e;
		}

	}

}

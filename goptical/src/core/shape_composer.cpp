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

#include <limits>

#include <goptical/core/math/transform.hpp>
#include <goptical/core/math/triangle.hpp>
#include <goptical/core/math/vector_pair.hpp>
#include <goptical/core/shape/composer.hpp>

namespace goptical
{

	namespace shape
	{

		Composer::Composer ()
			: _list (), _update (false), _global_dist (true), _max_radius (0.0),
			  _min_radius (std::numeric_limits<double>::max ()),
			  _bbox (math::vector2_pair_00), _contour_cnt (0)
		{
		}

		Composer::Attributes::Attributes (const std::shared_ptr<Base> &shape)
			: _shape (shape), _list ()
		{
			_transform.reset ();
			_inv_transform.reset ();
		}

		Composer::Attributes &
		Composer::add_shape (const std::shared_ptr<Base> &shape)
		{
			_list.push_back (Attributes (shape));
			_update = true;
			return _list.back ();
		}

		Composer::Attributes &
		Composer::Attributes::include (const std::shared_ptr<Base> &shape)
		{
			_list.push_back (Attributes (shape));
			_list.back ()._exclude = false;
			return _list.back ();
		}

		Composer::Attributes &
		Composer::Attributes::exclude (const std::shared_ptr<Base> &shape)
		{
			_list.push_back (Attributes (shape));
			_list.back ()._exclude = true;
			return _list.back ();
		}

		bool
		Composer::Attributes::inside (const math::Vector2 &point) const
		{
			math::Vector2 tp (_inv_transform.transform (point));
			bool res = _shape->inside (tp);
for (auto &s : _list)
			{
				res &= s.inside (tp);
			}
			return res ^ _exclude;
		}

		bool
		Composer::inside (const math::Vector2 &point) const
		{
for (auto &s : _list)
				if (s.inside (point))
				{
					return true;
				}
			return false;
		}

		void
		Composer::update ()
		{
			math::Vector2 a (0);
			math::Vector2 b (0);
			_contour_cnt = 0;
for (auto &s : _list)
			{
				// update max radius
				double m = s._transform.transform (math::vector2_0).len ()
				           + s._shape->max_radius ();
				if (m > _max_radius)
				{
					_max_radius = m;
				}
				if (m < _min_radius)
				{
					_min_radius = m;
				}
				// update bounding box
				math::VectorPair2 bi
				    = s._transform.transform_pair (s._shape->get_bounding_box ());
				for (unsigned int j = 0; j < 2; j++)
				{
					if (bi[0][j] > bi[1][j])
					{
						std::swap (bi[0][j], bi[1][j]);
					}
					if (bi[0][j] < a[j])
					{
						a[j] = bi[0][j];
					}
					if (bi[1][j] > b[j])
					{
						b[j] = bi[1][j];
					}
				}
				// update contour count
				_contour_cnt += s._shape->get_contour_count ();
			}
			_bbox = math::VectorPair2 (a, b);
			_update = false;
		}

		void
		Composer::update () const
		{
			const_cast<Composer *> (this)->update ();
		}

		double
		Composer::max_radius () const
		{
			if (_update)
			{
				update ();
			}
			return _max_radius;
		}

		double
		Composer::min_radius () const
		{
			if (_update)
			{
				update ();
			}
			return _min_radius;
		}

		double
		Composer::get_outter_radius (const math::Vector2 &dir) const
		{
			// FIXME
			return _max_radius;
		}

		double
		Composer::get_hole_radius (const math::Vector2 &dir) const
		{
			// FIXME
			return 0;
		}

		math::VectorPair2
		Composer::get_bounding_box () const
		{
			if (_update)
			{
				update ();
			}
			return _bbox;
		}

		void
		Composer::get_pattern (const math::Vector2::put_delegate_t &f,
		                       const trace::Distribution &d, bool unobstructed) const
		{
			if (_global_dist)
			{
				Base::get_pattern (f, d, unobstructed);
			}
			else
			{
for (auto &s : _list)
				{
					auto de = [&] (const math::Vector2 &v)
					{
						math::Vector2 p = s._transform.transform (v);
for (auto &s1 : s._list)
							if (!s1._exclude
							        ^ s1._shape->inside (s1._inv_transform.transform (p)))
							{
								return;
							}
						f (p);
					};
					s._shape->get_pattern (de, d, unobstructed);
				}
			}
		}

		unsigned int
		Composer::get_contour_count () const
		{
			if (_update)
			{
				update ();
			}
			return _contour_cnt;
		}

		void
		Composer::get_contour (unsigned int contour,
		                       const math::Vector2::put_delegate_t &f,
		                       double resolution) const
		{
			// FIXME add contour boolean operations
for (auto &s : _list)
			{
				unsigned int c = s._shape->get_contour_count ();
				if (contour < c)
				{
					auto de = [&] (const math::Vector2 &v)
					{
						f (s._transform.transform (v));
					};
					return s._shape->get_contour (contour, de, resolution);
				}
				contour -= c;
			}
		}

		void
		Composer::get_triangles (const math::Triangle<2>::put_delegate_t &f,
		                         double resolution) const
		{
for (auto &s : _list)
			{
				auto de = [&] (const math::Triangle<2> &t)
				{
					math::Triangle<2> p;
					for (unsigned int i = 0; i < 3; i++)
					{
						p[i] = s._transform.transform (t[i]);
					}
					f (p);
				};
				s._shape->get_triangles (de, resolution);
			}
		}
	}
}

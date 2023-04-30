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

#include <goptical/core/io/renderer_viewport.hpp>
#include <goptical/core/math/transform.hpp>
#include <goptical/core/math/vector_pair.hpp>
#include <goptical/core/sys/container.hpp>
#include <goptical/core/sys/element.hpp>

#include <goptical/core/error.hpp>

#include <limits>

namespace goptical
{

	namespace sys
	{

		Container::Container () : _list () {}

		Container::~Container ()
		{
			remove_all ();
		}

		void
		Container::remove_all ()
		{
			_list.clear ();
		}

		void
		Container::add_front (const std::shared_ptr<Element> &e)
		{
			_list.insert (_list.begin (), e);
		}

		void
		Container::add (const std::shared_ptr<Element> &e)
		{
			_list.push_back (e);
		}

		void
		Container::remove (const std::shared_ptr<Element> &e)
		{
			_list.remove (e);
		}

		void
		Container::remove (const Element *e)
		{
			// FIXME
			auto result = std::find_if (std::begin (_list), std::end (_list),
			                            [&] (const std::shared_ptr<Element> other)
			{
				return other.get () == e;
			});
			if (result != std::end (_list))
			{
				remove (*result);
			}
		}

		math::VectorPair3
		Container::get_bounding_box () const
		{
			math::Vector3 a (std::numeric_limits<double>::max ());
			math::Vector3 b (-std::numeric_limits<double>::max ());
for (auto &i : get_element_list ())
			{
				math::VectorPair3 bi = i->get_bounding_box ();
				if (bi[0] == bi[1])
				{
					continue;
				}
				bi = i->get_transform ().transform_pair (bi);
				for (unsigned int j = 0; j < 3; j++)
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
			}
			return math::VectorPair3 (a, b);
		}

		void
		Container::draw_2d_fit (io::RendererViewport &r, bool keep_aspect) const
		{
			math::VectorPair3 b = get_bounding_box ();
			r.set_window (math::VectorPair2 (b, 2, 1), keep_aspect);
			r.set_camera_direction (math::vector3_100);
			r.set_camera_position (math::vector3_0);
			// 200 - curve approximation resolution
			r.set_feature_size (b[1].y () - b[0].y () / 200.);
		}

		void
		Container::draw_2d (io::Renderer &r) const
		{
			// optical axis
			math::VectorPair3 b = get_bounding_box ();
			r.draw_segment (math::VectorPair2 (b.z0 (), 0., b.z1 (), 0.), io::rgb_gray);
			if (const Element *e = dynamic_cast<const Element *> (this))
			{
				return r.draw_element_2d (*e, e);
			}
for (auto &i : get_element_list ())
			{
				r.draw_element_2d (*i, 0);
			}
		}

		void
		Container::draw_3d_fit (io::RendererViewport &r, double z_offset) const
		{
			math::Transform<3> t;
			t.set_direction (-math::vector3_100);
			t.translation_reset ();
			math::VectorPair3 b = get_bounding_box ();
			std::swap (b[0].x (), b[0].z ());
			std::swap (b[1].x (), b[1].z ());
			math::Vector3 center = (b[0] + b[1]) / 2.;
			double width
			    = (center.x () - b[1].x ()) / tan (math::degree2rad (r.get_fov ()) / 2.);
			double dist = width + (center.z () + b[0].z ()) + z_offset;
			t.set_translation (t.transform (center) + math::Vector3 (dist, 0, 0));
			r.set_camera_transform (t.inverse ());
			// 200 is a resolution of 3d objects parameter
			r.set_feature_size (fabs (width / 200.));
		}

		void
		Container::draw_3d (io::Renderer &r) const
		{
			if (const Element *e = dynamic_cast<const Element *> (this))
			{
				return r.draw_element_3d (*e, e);
			}
for (auto &i : get_element_list ())
			{
				r.draw_element_3d (*i, 0);
			}
		}

		std::ostream &
		operator<< (std::ostream &o, const Container &c)
		{
for (auto &i : c._list)
			{
				o << "  " << *i << std::endl;
			}
			return o;
		}

	}
}

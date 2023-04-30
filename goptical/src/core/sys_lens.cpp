/*

      This file is part of the Goptical Core library.

      The Goptical library is free software; you can redistribute it
      and/or modify it under the terms of the GNU General Public
      License as published by the Free Software Foundation; either
      version 3 of the License, or (at your option) any later version.

      The Goptical library is distributed in the hope that it will be
      useful, but WITHOUT ANY WARRANTY; without even the implied
      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
      See the GNU General Public License for more details.

      You should have received a copy of the GNU General Public
      License along with the Goptical library; if not, write to the
      Free Software Foundation, Inc., 59 Temple Place, Suite 330,
      Boston, MA 02111-1307 USA

      Copyright (C) 2010-2011 Free Software Foundation, Inc
      Author: Alexandre Becoulet

*/

#include <goptical/core/sys/group.hpp>
#include <goptical/core/sys/lens.hpp>
#include <goptical/core/sys/optical_surface.hpp>
#include <goptical/core/sys/stop.hpp>
#include <goptical/core/sys/system.hpp>

#include <goptical/core/material/solid.hpp>

#include <goptical/core/curve/flat.hpp>
#include <goptical/core/curve/sphere.hpp>
#include <goptical/core/shape/disk.hpp>

#include <goptical/core/math/triangle.hpp>
#include <goptical/core/math/vector.hpp>

#include <goptical/core/delegate.hpp>

#include <goptical/core/io/renderer.hpp>

#include <goptical/core/trace/ray.hpp>



namespace goptical
{

	namespace sys
	{

		Lens::Lens (const math::VectorPair3 &p, double offset,
		            const std::shared_ptr<material::Base> &env)
			: Group (p), _last_pos (offset), _next_mat (env)
		{			
		}

		Lens::Lens (const math::VectorPair3 &p,
		            const std::shared_ptr<curve::Base> &curve0,
		            const std::shared_ptr<shape::Base> &shape0,
		            const std::shared_ptr<curve::Base> &curve1,
		            const std::shared_ptr<shape::Base> &shape1, double thickness0,
		            const std::shared_ptr<material::Base> &glass0,
		            const std::shared_ptr<material::Base> &env)
			: Group (p), _last_pos (0), _next_mat (env)
		{
			_surfaces.reserve (2);
			add_surface (curve0, shape0, thickness0, glass0);
			add_surface (curve1, shape1, 0, env);
		}

		Lens::Lens (const math::VectorPair3 &p, double roc0, double ap_radius0,
		            double roc1, double ap_radius1, double thickness0,
		            const std::shared_ptr<material::Base> &glass0,
		            const std::shared_ptr<material::Base> &env)
			: Group (p), _last_pos (0), _next_mat (env)
		{
			_surfaces.reserve (2);
			add_surface (roc0, ap_radius0, thickness0, glass0);
			add_surface (roc1, ap_radius1, 0, env);
		}

		Lens::~Lens () {}

		unsigned int
		Lens::add_surface (const std::shared_ptr<curve::Base> &curve,
		                   const std::shared_ptr<shape::Base> &shape, double thickness,
		                   const std::shared_ptr<material::Base> &glass)
		{
			assert (thickness >= 0.);
			auto s = std::make_shared<OpticalSurface> (
			             math::VectorPair3 (0, 0, _last_pos), curve, shape, _next_mat, glass);
			_surfaces.push_back (s);
			s->set_parent (this);
			_next_mat = glass;
			_last_pos += thickness;
			Container::add (s);
			return _surfaces.size () - 1;
		}

		unsigned int Lens::add_surface (double roc, double radius, double thickness,
		                   const std::shared_ptr<material::Base> &glass)
		{
			std::shared_ptr<curve::Base> curve;
			if (roc == 0.)
			{
				curve = curve::flat;
			}
			else
			{
				curve = std::make_shared<curve::Sphere> (roc);
			}
			return add_surface (curve, std::make_shared<shape::Disk> (radius), thickness,
			                    glass);
		}

		void Lens::add_stop (const std::shared_ptr<shape::Base> &shape, double thickness)
		{
			if (_stop)
			{
				throw Error ("Can not add more than one stop per Lens");
			}
			_stop = std::make_shared<Stop> (math::VectorPair3 (0, 0, _last_pos), shape);
			_last_pos += thickness;
			Container::add (_stop);
			_stop->set_parent (this);
		}

		void Lens::add_stop (double radius, double thickness)
		{
			return add_stop (std::make_shared<shape::Disk> (radius), thickness);
		}

		double Lens::get_thickness (unsigned int index) const
		{
			double z = index + 1 == _surfaces.size ()
			           ? _last_pos
			           : _surfaces.at (index + 1)->get_local_position ().z ();
			return z - _surfaces.at (index)->get_local_position ().z ();
		}

		void Lens::set_thickness (double thickness, unsigned int index)
		{
			double diff = thickness - get_thickness (index);
			for (unsigned int i = index; i < _surfaces.size (); i++)
			{
				math::Vector3 p = _surfaces[i]->get_local_position ();
				p.z () += diff;
				_surfaces[i]->set_local_position (p);
			}
			_last_pos += diff;
		}

		void Lens::set_left_material (const std::shared_ptr<material::Base> &m)
		{
			_surfaces.front ()->set_material (0, m);
		}

		void Lens::set_right_material (const std::shared_ptr<material::Base> &m)
		{
			_surfaces.back ()->set_material (1, m);
		}

		void Lens::set_glass_material (const std::shared_ptr<material::Base> &m,
		                          unsigned int index)
		{
			_surfaces.at (index + 1)->set_material (0, m);
			_surfaces.at (index)->set_material (1, m);
		}

		void Lens::set_left_curve (const std::shared_ptr<curve::Base> &c)
		{
			_surfaces.front ()->set_curve (c);
		}

		void Lens::set_right_curve (const std::shared_ptr<curve::Base> &c)
		{
			_surfaces.back ()->set_curve (c);
		}

		void Lens::set_curve (const std::shared_ptr<curve::Base> &c, unsigned int index)
		{
			_surfaces.at (index)->set_curve (c);
		}

		void Lens::set_shape (const std::shared_ptr<shape::Base> &s)
		{
			for (unsigned int i = 0; i < _surfaces.size (); i++)
			{
				_surfaces[i]->set_shape (s);
			}
		}

		void Lens::set_shape (const std::shared_ptr<shape::Base> &s, unsigned int index)
		{
			_surfaces.at (index)->set_shape (s);
		}

		math::VectorPair3 Lens::get_exit_plane () const
		{
			return get_transform ().transform_line (
			           math::VectorPair3 (0., 0., _last_pos));
		}

		void Lens::draw_3d_e (io::Renderer &r, const Element *ref) const
		{
			// surfaces
			Group::draw_3d_e (r, ref);
#if 1			
			// draw lens contours
			for (unsigned int i = 0; i < _surfaces.size() - 1; i++)
			{
				std::shared_ptr <Surface> left  = _surfaces[i];
				std::shared_ptr<Surface> right  = _surfaces[i + 1];
				const shape::Base &s = left->get_shape();
				io::Rgb color = left->get_color (r);
				
				if (&s == &(right->get_shape ()) )
				{
					continue;
				}
				for (unsigned int i = 0; i < s.get_contour_count(); i++)
				{
					// get 2d contour points
					std::vector<math::Vector2>  contour;
					delegate_push< std::vector<math::Vector2> > contour_push (contour);
					s.get_contour(i, contour_push, r.get_feature_size());
					unsigned int j;
					unsigned int count = contour.size();
					if (count < 2)
					{
						continue;
					}
					std::vector<math::Vector3> pr(count);
					std::vector < math::Vector3> pl(count);
					// compute 3d contour points
					const math::Transform<3> &rtr = right->get_global_transform();
					const math::Transform<3> &ltr = left->get_global_transform();
					for (j = 0; j < count; j++)
					{
						pr[j] = rtr.transform(math::Vector3(contour[j], right->get_curve().sagitta(contour[j])));
						pl[j] = ltr.transform(math::Vector3(contour[j], left->get_curve().sagitta(contour[j])));
					}
					// compute normals and draw
					math::Vector3 prevn(math::Triangle<3>(pr[count - 1], pl[count - 1], pl[0]).normal());
					math::Triangle<3> cur(pr[0], pl[0], pl[1]);
					math::Vector3 curn(cur.normal());
					for (j = 0; j < count; j++)
					{
						math::Triangle<3> next(pr[(j+1) % count], pl[(j+1) % count], pl[(j+2) % count]);
						math::Vector3 nextn(next.normal());
						prevn=prevn.normalize();
						curn=curn.normalize();
						nextn=nextn.normalize();
						//math::Vector3 n1((prevn + curn) * 0.5);
						//math::Vector3 n2((curn + nextn) * 0.5);
						math::Vector3 n1(curn);
						math::Vector3 n2(curn);

						r.draw_triangle(cur, math::Triangle<3>(n1, n1, n2), color);
						r.draw_triangle(math::Triangle<3>(pl[(j+1) % count], pr[(j+1) % count], pr[j]), math::Triangle<3>(n2, n2, n1), color);
						prevn = curn;
						cur = next;
						curn = nextn;
					}
				}
				
			}
#endif
		}

		void
		Lens::draw_2d_edge (io::Renderer &r, const Surface &left, double l_y,
		                    const Surface &right, double r_y, LensEdge type,
		                    const Element *ref) const
		{
			const math::Vector3 l3 (0., l_y,
			                        left.get_curve ().sagitta (math::Vector2 (0., l_y)));
			const math::Vector2 l2 (
			    left.get_transform_to (ref).transform (l3).project_zy ());
			const math::Vector3 r3 (
			    0., r_y, right.get_curve ().sagitta (math::Vector2 (0., r_y)));
			const math::Vector2 r2 (
			    right.get_transform_to (ref).transform (r3).project_zy ());
			switch (type)
			{
				case StraightEdge:
					{
						if (fabs (l2.y () - r2.y ()) > 1e-6)
						{
							double m;
							if (fabs (l2.y ()) > fabs (r2.y ()))
							{
								m = l2.y ();
								r.draw_segment (
								    math::VectorPair2 (r2.x (), m, r2.x (), r2.y ()),
								    left.get_color (r));
							}
							else
							{
								m = r2.y ();
								r.draw_segment (
								    math::VectorPair2 (l2.x (), m, l2.x (), l2.y ()),
								    left.get_color (r));
							}
							r.draw_segment (math::VectorPair2 (l2.x (), m, r2.x (), m),
							                left.get_color (r));
							break;
						}
					}
				case SlopeEdge:
					r.draw_segment (l2, r2, left.get_color (r));
					break;
			}
		}

#define GRP_BEGIN                                                             \
	do                                                                          \
	{                                                                         \
		if (!grp)                                                               \
		{                                                                     \
			r.group_begin ();                                                   \
			grp = true;                                                         \
		}                                                                     \
	}                                                                         \
	while (0)
#define GRP_END                                                               \
	do                                                                          \
	{                                                                         \
		if (grp)                                                                \
		{                                                                     \
			r.group_end ();                                                     \
			grp = false;                                                        \
		}                                                                     \
	}                                                                         \
	while (0)

		void
		Lens::draw_2d_e (io::Renderer &r, const Element *ref) const
		{
			bool grp = false;
			if (_stop)
			{
				(static_cast<Element *> (_stop.get ()))->draw_2d_e (r, ref);
			}
			if (_surfaces.empty ())
			{
				return;
			}
			auto const &first = _surfaces[0];
			if (&first->get_material (1) != &first->get_material (0))
			{
				GRP_BEGIN;
				(static_cast<Element *> (first.get ()))->draw_2d_e (r, ref);
			}
			for (unsigned int i = 0; i < _surfaces.size () - 1; i++)
			{
				auto const &left = _surfaces[i];
				auto const &right = _surfaces[i + 1];
				if (!dynamic_cast<const material::Solid *> (&left->get_material (1)))
				{
					GRP_END;
				}
				else
				{
					// draw outter edges
					double left_top_edge
					    = left->get_shape ().get_outter_radius (math::vector2_01);
					double left_bot_edge
					    = -left->get_shape ().get_outter_radius (-math::vector2_01);
					double right_top_edge
					    = right->get_shape ().get_outter_radius (math::vector2_01);
					double right_bot_edge
					    = -right->get_shape ().get_outter_radius (-math::vector2_01);
					draw_2d_edge (r, *left, left_top_edge, *right, right_top_edge,
					              StraightEdge, ref);
					draw_2d_edge (r, *left, left_bot_edge, *right, right_bot_edge,
					              StraightEdge, ref);
					// draw hole edges if not coincident
					double left_top_hole
					    = left->get_shape ().get_hole_radius (math::vector2_01);
					double left_bot_hole
					    = -left->get_shape ().get_hole_radius (-math::vector2_01);
					double right_top_hole
					    = right->get_shape ().get_hole_radius (math::vector2_01);
					double right_bot_hole
					    = -right->get_shape ().get_hole_radius (-math::vector2_01);
					if (fabs (left_bot_hole - left_top_hole) > 1e-6
					        || fabs (right_bot_hole - right_top_hole) > 1e-6)
					{
						draw_2d_edge (r, *left, left_top_hole, *right, right_top_hole,
						              SlopeEdge, ref);
						draw_2d_edge (r, *left, left_bot_hole, *right, right_bot_hole,
						              SlopeEdge, ref);
					}
				}
				if (&right->get_material (1) != &right->get_material (0))
				{
					GRP_BEGIN;
					(static_cast<Element *> (right.get ()))->draw_2d_e (r, ref);
				}
			}
			GRP_END;
		}
	}

}

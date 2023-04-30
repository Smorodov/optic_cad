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

#include <goptical/core/material/base.hpp>
#include <goptical/core/sys/element.hpp>
#include <goptical/core/sys/surface.hpp>

#include <goptical/core/shape/base.hpp>
#include <goptical/core/shape/ring.hpp>

#include <goptical/core/curve/base.hpp>

#include <goptical/core/math/triangle.hpp>
#include <goptical/core/math/vector.hpp>

#include <goptical/core/light/ray.hpp>

#include <goptical/core/trace/distribution.hpp>
#include <goptical/core/trace/params.hpp>
#include <goptical/core/trace/ray.hpp>
#include <goptical/core/trace/result.hpp>

#include <goptical/core/io/renderer.hpp>
#include <goptical/core/io/rgb.hpp>

namespace goptical
{

	namespace sys
	{

		Surface::Surface (const math::VectorPair3 &p,
		                  const std::shared_ptr<curve::Base> &curve,
		                  const std::shared_ptr<shape::Base> &shape)
			: Element (p), _discard_intensity (0), _curve (curve), _shape (shape)
		{
		}

		Surface::~Surface () {}

		void
		Surface::get_pattern (const math::Vector3::put_delegate_t &f,
		                      const trace::Distribution &d, bool unobstructed) const
		{
			auto de = [&] (const math::Vector2 &v2d)
			{
				f (math::Vector3 (v2d, _curve->sagitta (v2d)));
			};
			// get distribution from shape
			_shape->get_pattern (de, d, unobstructed);
		}

		void
		Surface::trace_ray_simple (trace::Result &result, trace::Ray &incident,
		                           const math::VectorPair3 &local,
		                           const math::VectorPair3 &intersect) const
		{
			throw Error ("simple ray trace not handled by this surface class");
		}

		void
		Surface::trace_ray_intensity (trace::Result &result, trace::Ray &incident,
		                              const math::VectorPair3 &local,
		                              const math::VectorPair3 &intersect) const
		{
			throw Error ("intensity ray trace not handled by this surface class");
		}

		void
		Surface::trace_ray_polarized (trace::Result &result, trace::Ray &incident,
		                              const math::VectorPair3 &local,
		                              const math::VectorPair3 &intersect) const
		{
			throw Error ("polarized ray trace not handled by this surface class");
		}

		bool
		Surface::intersect (const trace::Params &params, math::VectorPair3 &pt,
		                    const math::VectorPair3 &ray) const
		{
			if (!_curve->intersect (pt.origin (), ray))
			{
				return false;
			}
			if (!params.get_unobstructed ()
			        && !_shape->inside (pt.origin ().project_xy ()))
			{
				return false;
			}
			_curve->normal (pt.normal (), pt.origin ());
			if (ray.direction ().z () < 0)
			{
				pt.normal () = -pt.normal ();
			}
			return true;
		}

		template <trace::IntensityMode m>
		void
		Surface::trace_ray (trace::Result &result, trace::Ray &incident,
		                    const math::VectorPair3 &local,
		                    const math::VectorPair3 &pt) const
		{
			incident.set_len ((pt.origin () - local.origin ()).len ());
			incident.set_intercept (*this, pt.origin ());
			if (m == trace::Simpletrace)
			{
				incident.set_intercept_intensity (1.0);
				return trace_ray_simple (result, incident, local, pt);
			}
			else
			{
				// apply absorbtion from current material
				double i_intensity
				    = incident.get_intensity ()
				      * incident.get_material ()->get_internal_transmittance (
				          incident.get_wavelen (), incident.get_len ());
				incident.set_intercept_intensity (i_intensity);
				if (i_intensity < _discard_intensity)
				{
					return;
				}
				if (m == trace::Intensitytrace)
				{
					return trace_ray_intensity (result, incident, local, pt);
				}
				else if (m == trace::Polarizedtrace)
				{
					return trace_ray_polarized (result, incident, local, pt);
				}
				else
				{
					abort ();
				}
			}
		}

		template void Surface::trace_ray<trace::Simpletrace> (
		    trace::Result &result, trace::Ray &incident,
		    const math::VectorPair3 &local, const math::VectorPair3 &pt) const;
		template void Surface::trace_ray<trace::Intensitytrace> (
		    trace::Result &result, trace::Ray &incident,
		    const math::VectorPair3 &local, const math::VectorPair3 &pt) const;
		template void Surface::trace_ray<trace::Polarizedtrace> (
		    trace::Result &result, trace::Ray &incident,
		    const math::VectorPair3 &local, const math::VectorPair3 &pt) const;

		template <trace::IntensityMode m>
		inline void
		Surface::process_rays_ (trace::Result &result,
		                        trace::rays_queue_t *input) const
		{
			const trace::Params &params = result.get_params ();
for (auto &i : *input)
			{
				math::VectorPair3 pt;
				trace::Ray &ray = *i;
				const math::Transform<3> &t
				    = ray.get_creator ()->get_transform_to (*this);
				math::VectorPair3 local (t.transform_line (ray));
				if (intersect (params, pt, local))
				{
					result.add_intercepted (*this, ray);
					trace_ray<m> (result, ray, local, pt);
				}
			}
		}

		void
		Surface::process_rays_simple (trace::Result &result,
		                              trace::rays_queue_t *input) const
		{
			process_rays_<trace::Simpletrace> (result, input);
		}

		void
		Surface::process_rays_intensity (trace::Result &result,
		                                 trace::rays_queue_t *input) const
		{
			process_rays_<trace::Intensitytrace> (result, input);
		}

		void
		Surface::process_rays_polarized (trace::Result &result,
		                                 trace::rays_queue_t *input) const
		{
			process_rays_<trace::Polarizedtrace> (result, input);
		}

		io::Rgb
		Surface::get_color (const io::Renderer &r) const
		{
			return r.get_style_color (io::StyleSurface);
		}

		math::VectorPair3
		Surface::get_bounding_box () const
		{
			math::VectorPair2 sb = _shape->get_bounding_box ();
			// FIXME we assume curve is symetric here
			double z = 0;
			double ms = _curve->sagitta (math::Vector2 (_shape->max_radius ()));
			if (z > ms)
			{
				std::swap (z, ms);
			}
			return math::VectorPair3 (math::Vector3 (sb[0].x (), sb[0].y (), z),
			                          math::Vector3 (sb[1].x (), sb[1].y (), ms));
		}

		void
		Surface::draw_3d_e (io::Renderer &r, const Element *ref) const
		{
			io::Rgb color = get_color (r);
			std::vector<math::Triangle<2> > mesh;
			_shape->get_triangles (
			    [&] (const math::Triangle<2> &in)
			{
				mesh.push_back (in);
			},
			r.get_feature_size ());
			const math::Transform<3> &tr = get_global_transform ();
for (auto &t : mesh)
			{
				math::Triangle<3> pts, nrm;
				for (unsigned int i = 0; i < 3; i++)
				{
					pts[i].x () = t[i].x ();
					pts[i].y () = t[i].y ();
					pts[i].z () = _curve->sagitta (t[i]);
					_curve->normal (nrm[i], pts[i]);
					pts[i] = tr.transform (pts[i]);
					nrm[i] = tr.transform_linear (nrm[i]);
				}
				r.draw_triangle (pts, nrm, color);
			}
		}

		void
		Surface::get_2d_points (math::Vector2 *array, unsigned int count, double start,
		                        double end, const Element *ref) const
		{
			assert (count > 1);
			double y1 = start;
			double step = (end - start) / (count - 1);
			int i;
			const math::Transform<3> &t = get_transform_to (ref);
			for (i = 0; i < (int)count; i++)
			{
				math::Vector3 v (0., y1, 0.);
				v.z () = _curve->sagitta (v.project_xy ());
				array[i] = t.transform (v).project_zy ();
				y1 += step;
			}
		}

		void
		Surface::draw_2d_e (io::Renderer &r, const Element *ref) const
		{
			double top_edge = _shape->get_outter_radius (math::vector2_01);
			double top_hole = _shape->get_hole_radius (math::vector2_01);
			double bot_edge = -_shape->get_outter_radius (-math::vector2_01);
			double bot_hole = -_shape->get_hole_radius (-math::vector2_01);
			unsigned int res = std::max (
			                       100,
			                       std::min (1, (int)(fabs (top_edge - bot_edge) / r.get_feature_size ())));
			if (fabs (bot_hole - top_hole) > 1e-6)
			{
				DPP_VLARRAY (math::Vector2, res / 2, p);
				get_2d_points (&p[0], res / 2, top_edge, top_hole, ref);
				r.draw_polygon (&p[0], res / 2, get_color (r), false, false);
				get_2d_points (&p[0], res / 2, bot_hole, bot_edge, ref);
				r.draw_polygon (&p[0], res / 2, get_color (r), false, false);
			}
			else
			{
				DPP_VLARRAY (math::Vector2, res, p);
				get_2d_points (&p[0], res, top_edge, bot_edge, ref);
				r.draw_polygon (&p[0], res, get_color (r), false, false);
			}
		}

	}

}

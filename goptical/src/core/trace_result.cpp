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

#include <goptical/core/sys/element.hpp>
#include <goptical/core/sys/system.hpp>

#include <goptical/core/trace/ray.hpp>
#include <goptical/core/trace/result.hpp>

#include <goptical/core/math/vector.hpp>
#include <goptical/core/math/vector_pair.hpp>

#include <goptical/core/io/renderer.hpp>

namespace goptical
{

	namespace trace
	{

		Result::Result ()
			: _rays (), _elements (), _wavelengths (), _generated_queue (0),
			  _sources (), _bounce_limit_count (0), _system (0)
		{
		}

		Result::~Result ()
		{
			clear ();
		}

		void
		Result::clear_save_states ()
		{
for (auto &i : _elements)
			{
				i._save_intercepted_list = false;
				i._save_generated_list = false;
			}
		}

		void
		Result::clear ()
		{
for (auto &i : _elements)
			{
				if (i._intercepted)
				{
					i._intercepted = nullptr;
				}
				if (i._generated)
				{
					i._generated = nullptr;
				}
			}
			_rays.clear (); // = vector_pool<Ray, 256>();
			_rays.shrink ();
			_sources.clear ();
			_wavelengths.clear ();
			_bounce_limit_count = 0;
		}

		void
		Result::prepare ()
		{
			clear ();
for (auto &i : _elements)
			{
				if (i._save_intercepted_list)
				{
					i._intercepted = std::make_shared<rays_queue_t> ();
				}
				if (i._save_generated_list)
				{
					i._generated = std::make_shared<rays_queue_t> ();
				}
			}
		}

		void
		Result::init (const sys::System *system)
		{
			static const struct element_result_s er = { 0 };
			if (!_system)
			{
				_system = system;
			}
			if (_system != system)
			{
				throw Error ("trace::Result used with multiple sys::system objects");
			}
			_elements.resize (system->get_element_count (), er);
		}

		void
		Result::init (const sys::Element &element)
		{
			auto system = element.get_system ();
			assert (system);
			init (system);
		}

		void
		Result::set_intercepted_save_state (const sys::Element &e, bool enabled)
		{
			init (e);
			get_element_result (e)._save_intercepted_list = enabled;
		}

		void Result::set_generated_save_state (const sys::Element &e, bool enabled)
		{
			init (e);
			get_element_result (e)._save_generated_list = enabled;
		}

		bool Result::get_intercepted_save_state (const sys::Element &e)
		{
			return get_element_result (e)._save_intercepted_list;
		}

		bool Result::get_generated_save_state (const sys::Element &e)
		{
			return get_element_result (e)._save_generated_list;
		}

		math::VectorPair3 Result::get_intercepted_window (const sys::Surface &s) const
		{
			const rays_queue_t &intercepts = get_intercepted (s);
			if (intercepts.empty ())
			{
				throw Error ("no ray intercepts found on the surface");
			}
			const math::Vector3 &first = (*intercepts.begin ())->get_intercept_point ();
			math::VectorPair3 window (first, first);
for (auto &i : intercepts)
			{
				const math::Vector3 &ip = i->get_intercept_point ();
				if (window[0].x () > ip.x ())
				{
					window[0].x () = ip.x ();
				}
				else if (window[1].x () < ip.x ())
				{
					window[1].x () = ip.x ();
				}
				if (window[0].y () > ip.y ())
				{
					window[0].y () = ip.y ();
				}
				else if (window[1].y () < ip.y ())
				{
					window[1].y () = ip.y ();
				}
				if (window[0].z () > ip.z ())
				{
					window[0].z () = ip.z ();
				}
				else if (window[1].z () < ip.z ())
				{
					window[1].z () = ip.z ();
				}
			}
			return window;
		}

		std::vector<std::vector<double> >
		Result::pixelate (const sys::Surface &s) const
		{
			const rays_queue_t &intercepts = get_intercepted (s);
			if (intercepts.empty ())
			{
				throw Error ("no ray intercepts found on the surface");
			}
			//      math::VectorPair3 window = get_intercepted_window(s);
			const auto &shape = s.get_shape ();
			const auto &window = s.get_bounding_box ();
			auto result = std::vector<std::vector<double> > (
			                  1024, std::vector<double> (1024, 0));
for (auto &i : intercepts)
			{
				const math::Vector3 &ip = i->get_intercept_point ();
				math::Vector3 d = (ip - window[0]) / (window[1] - window[0]) * 1024.0;
				if (d[0] < 0)
				{
					d[0] = 0;
				}
				if (d[0] > 1023)
				{
					d[0] = 1023;
				}
				if (d[1] < 0)
				{
					d[1] = 0;
				}
				if (d[1] > 1023)
				{
					d[1] = 1023;
				}
				const double intensity = i->get_intercept_intensity ();
				result[d[0]][d[1]] += intensity;
			}
			return result;
		}

		math::Vector3
		Result::get_intercepted_center (const sys::Surface &s) const
		{
			math::VectorPair3 win = get_intercepted_window (s);
			return (win[0] + win[1]) / 2;
		}

		math::Vector3
		Result::get_intercepted_centroid (const sys::Surface &s) const
		{
			const rays_queue_t &intercepts = get_intercepted (s);
			unsigned int count = 0;
			math::Vector3 center (0, 0, 0);
			if (intercepts.empty ())
			{
				throw Error ("no ray intercepts found on the surface");
			}
for (auto &i : intercepts)
			{
				center += i->get_intercept_point ();
				count++;
			}
			center /= count;
			return center;
		}

		double
		Result::get_max_ray_intensity () const
		{
			double res = 0;
for (auto &r : _rays)
			{
				double i = r.get_intensity ();
				if (i > res)
				{
					res = i;
				}
			}
			return res;
		}

		void
		Result::draw_2d (io::Renderer &r, bool hit_image,
		                 const sys::Element *ref) const
		{
			/*
			if (ref == nullptr)
			                     {
			                             return;
			                     }
								*/
			r.draw_trace_result_2d (*this, hit_image, ref);
		}

		void
		Result::draw_3d (io::Renderer &r, bool hit_image,
		                 const sys::Element *ref) const
		{			
			r.draw_trace_result_3d (*this, hit_image, ref);
		}
	}
}

#include <goptical/core/io/renderer.hpp>

#include <goptical/core/trace/params.hpp>
#include <goptical/core/trace/ray.hpp>
#include <goptical/core/trace/result.hpp>

#include <goptical/core/sys/image.hpp>

#include <goptical/core/math/triangle.hpp>
#include <goptical/core/math/vector_pair.hpp>

#include <goptical/core/light/ray.hpp>
#include <goptical/core/light/spectral_line.hpp>

namespace goptical
{

	namespace io
	{

		enum
		{
		    RANDOM_MAX = 0x7fffffff
		};
		/* https://en.wikipedia.org/wiki/Lehmer_random_number_generator */
		/* because we want deterministic sequence of random numbers */
		uint32_t
		lcg_parkmiller (uint32_t *state)
		{
			return *state = (uint64_t)*state * 48271 % 0x7fffffff;
		}

		/* NOTE not threadsafe */
		static uint32_t seed = 42;
		static inline uint32_t
		random ()
		{
			return lcg_parkmiller (&seed);
		}

		Renderer::Renderer ()
			: _feature_size (1.0), _ray_color_mode (RayColorWavelen),
			  _intensity_mode (IntensityIgnore)
		{
			_styles_color[StyleForeground] = Rgb (1.0, 1.0, 1.0);
			_styles_color[StyleBackground] = Rgb (0.0, 0.0, 0.0);
			_styles_color[StyleRay] = Rgb (1.0, 0.0, 0.0);
			_styles_color[StyleSurface] = Rgb (0.5, 0.5, 1.0);
			_styles_color[StyleGlass] = Rgb (0.8, 0.8, 1.0);
		}

		void Renderer::group_begin (const std::string &name)
		{
		}

		void Renderer::group_end ()
		{
		}

		/**********************************************************************
		 * Optical elements drawing
		 */

		void
		Renderer::draw_element_2d (const sys::Element &e, const sys::Element *ref)
		{
			group_begin ("element");
			e.draw_2d_e (*this, ref);
			group_end ();
		}

		void Renderer::draw_element_3d (const sys::Element &e, const sys::Element *ref)
		{
			group_begin ("element");
			e.draw_3d_e (*this, ref);
			group_end ();
		}

		/**********************************************************************
		 * light ray drawing
		 */

		template <unsigned D, bool draw_lost>
		bool
		Renderer::draw_traced_ray_recurs (const trace::Ray &ray, double lost_len,
		                                  const sys::Element *ref, bool hit_image)
		{
			const math::Transform<3> &t1 = ray.get_creator ()->get_transform_to (ref);
			math::VectorPair3 p;
			sys::Element *i_element = 0;
			p[0] = t1.transform (ray.origin ());
			if (ray.is_lost ())
			{
				if (!draw_lost)
				{
					return false;
				}
				p[1] = t1.transform (ray.origin () + ray.direction () * lost_len);
			}
			else
			{
				i_element = &ray.get_intercept_element ();
				const math::Transform<3> &t2 = i_element->get_transform_to (ref);
				p[1] = t2.transform (ray.get_intercept_point ());
			}
			bool done = false;
			for (trace::Ray *r = ray.get_first_child (); r; r = r->get_next_child ())
			{
				done |= draw_traced_ray_recurs<D, false> (*r, lost_len, ref, hit_image);
			}
			if (!done && hit_image && !dynamic_cast<const sys::Image *> (i_element))
			{
				return false;
			}
			switch (D)
			{
				case 2:
					// skip non tangential rays in 2d mode
					if (fabs (p.x1 ()) > 1e-6)
					{
						return false;
					}
					draw_ray_line (
					    math::VectorPair2 (p[0].project_zy (), p[1].project_zy ()), ray);
					break;
				case 3:
					draw_ray_line (p, ray);
					break;
			}
			return true;
		}

		template <unsigned D>
		void
		Renderer::draw_trace_result (const trace::Result &result,
		                             const sys::Element *ref, bool hit_image)
		{
			const trace::Result::sources_t &sl = result.get_source_list ();
			double lost_len = result.get_params ().get_lost_ray_length ();
			if (sl.empty ())
			{
				throw Error ("No source found in trace result");
			}
			_max_intensity = result.get_max_ray_intensity ();
for (auto &s : sl)
			{
				try
				{
					const trace::rays_queue_t &rl
					    = result.get_generated (*(sys::Element *)s);
for (auto &r : rl)
					{
						group_begin ("ray");
						draw_traced_ray_recurs<D, false> (*r, lost_len, ref, hit_image);
						group_end ();
					}
				}
				catch (Error &e)
				{
					std::cerr << "Error occurred " << e.what () << "\n";
				}
			}
		}

		void
		Renderer::draw_trace_result_2d (const trace::Result &result, bool hit_image,
		                                const sys::Element *ref)
		{
			group_begin ("rays");
			draw_trace_result<2> (result, ref, hit_image);
			group_end ();
		}

		void
		Renderer::draw_trace_result_3d (const trace::Result &result, bool hit_image,
		                                const sys::Element *ref)
		{
			group_begin ("rays");
			draw_trace_result<3> (result, ref, hit_image);
			group_end ();
		}

		void
		Renderer::draw_intercepts (const trace::Result &result, const sys::Surface &s)
		{
			_max_intensity = result.get_max_ray_intensity ();
for (auto &i : result.get_intercepted (s))
			{
				const trace::Ray &ray = *i;
				// dont need global transform here, draw ray intercept points in
				// surface local coordinates.
				draw_point (ray.get_intercept_point ().project_xy (), ray_to_rgb (ray));
			}
		}

		const Rgb
		Renderer::ray_to_rgb (const light::Ray &ray)
		{
			switch (_ray_color_mode)
			{
				case RayColorWavelen:
					return light::SpectralLine::get_wavelen_color (ray.get_wavelen ());
				default:
				case RayColorFixed:
					return get_style_color (StyleRay);
			}
		}

		float
		Renderer::ray_to_alpha (const light::Ray &ray) const
		{
			switch (_intensity_mode)
			{
				case IntensityIgnore:
					return 0.0;
				case IntensityShade:
					return 1.0 - std::min (ray.get_intensity () / _max_intensity, 1.0);
				case IntensityLogShade: // FIXME add log
					return 1.0 - std::min (ray.get_intensity () / _max_intensity, 1.0);
			}
			return 0;
		}

		void
		Renderer::draw_ray_line (const math::VectorPair2 &l, const trace::Ray &ray)
		{
			draw_segment (l, ray_to_rgb (ray));
		}

		void
		Renderer::draw_ray_line (const math::VectorPair3 &l, const trace::Ray &ray)
		{
			draw_segment (l, ray_to_rgb (ray));
		}

		/**********************************************************************
		 * Misc shapes 2d drawing
		 */

		void
		Renderer::draw_polygon (const math::Vector2 *array, unsigned int count,
		                        const Rgb &rgb, bool filled, bool closed)
		{
			unsigned int i;
			if (count < 3)
			{
				return;
			}
			for (i = 0; i + 1 < count; i++)
			{
				draw_segment (math::VectorPair2 (array[i], array[i + 1]), rgb);
			}
			if (closed)
			{
				draw_segment (math::VectorPair2 (array[i], array[0]), rgb);
			}
		}

		void
		Renderer::draw_circle (const math::Vector2 &v, double r, const Rgb &rgb,
		                       bool filled)
		{
			unsigned int count
			    = std::min (100, std::max (1, (int)(2. * M_PI * r / _feature_size)));
			DPP_VLARRAY (math::Vector2, count, p);
			double astep = 2. * M_PI / count;
			double a = astep;
			p[0] = math::Vector2 (r, 0);
			for (unsigned int i = 0; i < count; i++, a += astep)
			{
				p[i] = v + math::Vector2 (r * cos (a), r * sin (a));
			}
			draw_polygon (&p[0], count, rgb, filled, true);
		}

		void
		Renderer::draw_triangle (const math::Triangle<3> &t, const Rgb &rgb)
		{
			draw_polygon (&t[0], 3, rgb, false, true);
		}

		void
		Renderer::draw_triangle (const math::Triangle<3> &t,
		                         const math::Triangle<3> &gradient, const Rgb &rgb)
		{
			draw_triangle (t, rgb);
		}

		void
		Renderer::draw_polygon (const math::Vector3 *array, unsigned int count,
		                        const Rgb &rgb, bool filled, bool closed)
		{
			if (count < 3)
			{
				return;
			}
			unsigned int i;
			for (i = 0; i + 1 < count; i++)
			{
				draw_segment (array[i], array[i + 1], rgb);
			}
			if (closed)
			{
				draw_segment (array[i], array[0], rgb);
			}
		}

		void
		Renderer::draw_box (const math::VectorPair2 &c, const Rgb &rgb)
		{
			draw_segment (math::Vector2 (c[0].x (), c[0].y ()),
			              math::Vector2 (c[1].x (), c[0].y ()), rgb);
			draw_segment (math::Vector2 (c[1].x (), c[1].y ()),
			              math::Vector2 (c[1].x (), c[0].y ()), rgb);
			draw_segment (math::Vector2 (c[1].x (), c[1].y ()),
			              math::Vector2 (c[0].x (), c[1].y ()), rgb);
			draw_segment (math::Vector2 (c[0].x (), c[0].y ()),
			              math::Vector2 (c[0].x (), c[1].y ()), rgb);
		}

		void
		Renderer::draw_triangle (const math::Triangle<2> &t, bool filled,
		                         const Rgb &rgb)
		{
			draw_polygon (&t[0], 3, rgb, filled, true);
		}

	}

}

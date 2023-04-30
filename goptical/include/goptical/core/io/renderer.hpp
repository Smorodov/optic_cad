
#ifndef GOPTICAL_RENDERER_HH_
#define GOPTICAL_RENDERER_HH_

#include <string>

#include "goptical/core/common.hpp"

#include "goptical/core/io/rgb.hpp"
#include "goptical/core/math/triangle.hpp"
#include "goptical/core/math/vector.hpp"
#include "goptical/core/math/vector_pair.hpp"

namespace goptical
{

	namespace io
	{

		/**
		   @short Base class for rendering drivers
		   @header <goptical/core/io/Renderer
		   @module {Core}
		   @main

		   This class define the interface for graphical rendering drivers
		   and provide a default implementation for some functions.
		 */

		class Renderer
		{
			public:
				void* user_data=nullptr;

				Renderer ();

				virtual inline ~Renderer ();

				GOPTICAL_ACCESSORS (
				    double, feature_size,
				    "size of lines and triangles used to render curved shapes.");

				/** Set color mode for light ray drawing. Default is @ref
				    RayColorWavelen. */
				inline void set_ray_color_mode (RayColorMode m);

				/** Set light ray intensity display mode */
				inline void set_ray_intensity_mode (IntensityMode m);

				/** Get foreground rgb color */
				inline const Rgb &rgb_foreground () const;

				/** Get foreground rgb color */
				inline const Rgb &rgb_background () const;

				/** Get rgb color from style specifier */
				inline const Rgb &get_style_color (Style s) const;

				/** Set rgb color for given style specifier. @pb Some drivers do not
				    support changing background color after initialization.  */
				inline void set_style_color (Style s, const Rgb &rgb);

				////////////// Internal stuff

				/** @internal Draw tangential rays found in trace result using 2d primitives.
				 */
				virtual void draw_trace_result_2d (const trace::Result &result,
				                                   bool hit_image, const sys::Element *ref);
				/** @internal Draw rays found in trace result using 3d primitives. */
				virtual void draw_trace_result_3d (const trace::Result &result,
				                                   bool hit_image, const sys::Element *ref);
				/** @internal Draw all optical elements in container using 2d primitives. */
				virtual void draw_element_2d (const sys::Element &e,
				                              const sys::Element *ref);
				/** @internal Draw all optical elements in container using 3d primitives. */
				virtual void draw_element_3d (const sys::Element &e,
				                              const sys::Element *ref);
				/** @internal Draw point corresponding to ray intercepts on a surface */
				virtual void draw_intercepts (const trace::Result &result,
				                              const sys::Surface &s);

				/** @internal ray line drawing in global coordinate, called by @ref
				 * draw_traced_ray_recurs */
				virtual void draw_ray_line (const math::VectorPair3 &l,
				                            const trace::Ray &ray);
				/** @internal ray line drawing in global coordinate, called by @ref
				 * draw_traced_ray_recurs */
				virtual void draw_ray_line (const math::VectorPair2 &l,
				                            const trace::Ray &ray);

				/** @internal Draw a point in 2d */
				virtual void draw_point (const math::Vector2 &p, const Rgb &rgb = rgb_gray,
				                         enum PointStyle s = PointStyleDot)
				    = 0;
				/** @internal Draw a line segment in 2d */
				virtual void draw_segment (const math::VectorPair2 &s,
				                           const Rgb &rgb = rgb_gray)
				    = 0;
				/** @internal Draw a line segment in 2d */
				inline void draw_segment (const math::Vector2 &a, const math::Vector2 &b,
				                          const Rgb &rgb = rgb_gray);
				/** @internal Draw a circle in 2d */
				virtual void draw_circle (const math::Vector2 &v, double r,
				                          const Rgb &rgb = rgb_gray, bool filled = false);
				/** @internal Draw text in 2d */
				virtual void draw_text (const math::Vector2 &pos, const math::Vector2 &dir,
				                        const std::string &str, TextAlignMask a, int size,
				                        const Rgb &rgb = rgb_gray)
				    = 0;
				/** @internal Draw polygon in 2d */
				virtual void draw_polygon (const math::Vector2 *array, unsigned int count,
				                           const Rgb &rgb = rgb_gray, bool filled = false,
				                           bool closed = true);
				/** @internal Draw a box in 2d */
				void draw_box (const math::VectorPair2 &corners, const Rgb &rgb = rgb_gray);
				/** @internal Draw a triangle in 2d */
				void draw_triangle (const math::Triangle<2> &t, bool filled = false,
				                    const Rgb &rgb = rgb_gray);

				/** @internal Draw a point in 3d */
				virtual void draw_point (const math::Vector3 &p, const Rgb &rgb = rgb_gray,
				                         enum PointStyle s = PointStyleDot)
				    = 0;
				/** @internal Draw a line segment in 3d */
				virtual void draw_segment (const math::VectorPair3 &l,
				                           const Rgb &rgb = rgb_gray)
				    = 0;
				/** @internal Draw a line segment in 3d */
				inline void draw_segment (const math::Vector3 &a, const math::Vector3 &b,
				                          const Rgb &rgb = rgb_gray);
				/** @internal Draw polygon in 3d */
				virtual void draw_polygon (const math::Vector3 *array, unsigned int count,
				                           const Rgb &rgb = rgb_gray, bool filled = false,
				                           bool closed = true);
				/** @internal Draw text in 3d */
				virtual void draw_text (const math::Vector3 &pos, const math::Vector3 &dir,
				                        const std::string &str, TextAlignMask a, int size,
				                        const Rgb &rgb = rgb_gray)
				    = 0;

				/** @internal Draw filled triangle in 3d */
				virtual void draw_triangle (const math::Triangle<3> &t, const Rgb &rgb);
				/** @internal Draw filled triangle in 3d */
				virtual void draw_triangle (const math::Triangle<3> &t,
				                            const math::Triangle<3> &gradient,
				                            const Rgb &rgb);

				/** @internal Get alpha channel from ray intensity and intensity mode */
				float ray_to_alpha (const light::Ray &ray) const;
				/** @internal Get rgb color from ray wavalen and ray color mode */
				const Rgb ray_to_rgb (const light::Ray &ray);

				/** @internal Begin group */
				virtual void group_begin (const std::string &name = "");
				/** @internal End group */
				virtual void group_end ();

			protected:
				void init_styles ();

				double _feature_size;

				Rgb _styles_color[StyleLast];
				RayColorMode _ray_color_mode;
				IntensityMode _intensity_mode;
				float _max_intensity; // max ray intensity updated on

			private:
				template <unsigned D>
				void draw_trace_result (const trace::Result &result, const sys::Element *ref,
				                        bool hit_image);
				template <unsigned D, bool draw_lost>
				bool draw_traced_ray_recurs (const trace::Ray &ray, double lost_len,
				                             const sys::Element *ref, bool hit_image);
		};

		Renderer::~Renderer () {}

		void
		Renderer::set_ray_color_mode (RayColorMode m)
		{
			_ray_color_mode = m;
		}

		void
		Renderer::set_ray_intensity_mode (IntensityMode m)
		{
			_intensity_mode = m;
		}

		const Rgb &
		Renderer::rgb_foreground () const
		{
			return _styles_color[StyleForeground];
		}

		const Rgb &
		Renderer::rgb_background () const
		{
			return _styles_color[StyleBackground];
		}

		const Rgb &
		Renderer::get_style_color (Style s) const
		{
			assert (s < StyleLast);
			return _styles_color[s];
		}

		void
		Renderer::set_style_color (Style s, const Rgb &rgb)
		{
			assert (s < StyleLast);
			_styles_color[s] = rgb;
		}

		void
		Renderer::draw_segment (const math::Vector2 &a, const math::Vector2 &b,
		                        const Rgb &rgb)
		{
			draw_segment (math::VectorPair2 (a, b), rgb);
		}

		void
		Renderer::draw_segment (const math::Vector3 &a, const math::Vector3 &b,
		                        const Rgb &rgb)
		{
			draw_segment (math::VectorPair3 (a, b), rgb);
		}

	}
}

#endif

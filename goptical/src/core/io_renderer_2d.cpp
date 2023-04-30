
#include <goptical/core/io/renderer_2d.hpp>

namespace goptical
{

	namespace io
	{

		Renderer2d::Renderer2d ()
		{
			_projection = &Renderer2d::projection_ortho;
			_cam_transform.reset ();
		}

		void
		Renderer2d::set_orthographic ()
		{
			_projection = &Renderer2d::projection_ortho;
		}

		void
		Renderer2d::set_perspective ()
		{
			double out_ratio
			    = (_2d_output_res.y () / _rows) / (_2d_output_res.x () / _cols);
			if (out_ratio < 1.)
			{
				_window2d = math::VectorPair2 (-1. / out_ratio, -1., 1. / out_ratio, 1.);
			}
			else
			{
				_window2d = math::VectorPair2 (-1, -out_ratio, 1., out_ratio);
			}
			_window2d_fit = _window2d;
			update_2d_window ();
			set_page (_pageid);
			_projection = &Renderer2d::projection_perspective;
			_eye_dist = 1. / tan (math::degree2rad (_fov) / 2.);
		}

		math::Vector2
		Renderer2d::projection_ortho (const math::Vector3 &v) const
		{
			math::Vector2 p (_cam_transform.transform (v).project_xy ());
			return p;
		}

		math::Vector2
		Renderer2d::projection_perspective (const math::Vector3 &v) const
		{
			math::Vector3 t (_cam_transform.transform (v));
			math::Vector2 p (t.x () * _eye_dist / -t.z (), t.y () * _eye_dist / -t.z ());
			return p;
		}

		math::Transform<3>
		Renderer2d::get_camera_transform () const
		{
			return _cam_transform;
		}

		void
		Renderer2d::set_camera_transform (const math::Transform<3> &t)
		{
			_cam_transform = t;
		}

		void
		Renderer2d::draw_point (const math::Vector3 &p, const Rgb &rgb,
		                        enum PointStyle s)
		{
			draw_point (project (p), rgb, s);
		}

		void
		Renderer2d::draw_segment (const math::VectorPair3 &l, const Rgb &rgb)
		{
			draw_segment (math::VectorPair2 (project (l[0]), project (l[1])), rgb);
		}

		void
		Renderer2d::draw_text (const math::Vector3 &pos, const math::Vector3 &dir,
		                       const std::string &str, TextAlignMask a, int size,
		                       const Rgb &rgb)
		{
			draw_text (project (pos), project (dir), str, a, size, rgb);
		}

	}

}

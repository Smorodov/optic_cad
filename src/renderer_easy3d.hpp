#ifndef GOPTICAL_RENDERER_OPENGL_HH_
#define GOPTICAL_RENDERER_OPENGL_HH_

#include <easy3d/core/surface_mesh.h>
#include <easy3d/core/surface_mesh_builder.h>
#include <easy3d/util/initializer.h>

#include "goptical/core/common.hpp"

#include "goptical/core/io/renderer_viewport.hpp"

namespace goptical
{

	namespace io
	{
		class Context
		{
		public:
			// for points and line segments
			std::vector<easy3d::vec3> points;
			std::vector<easy3d::vec4> points_colors;
			// for line segments
			std::vector<easy3d::vec4> segment_colors;
			std::vector<easy3d::vec3> points_segment;
			std::vector<easy3d::vec4> mesh_colors;
			std::vector<unsigned int> indices;
			std::vector< easy3d::SurfaceMesh* > meshes;
			inline void clear()
			{
				for(auto& m : meshes)
				{
					if(m!=nullptr)
					{
					delete m;
					}
				}
				meshes.clear();
				points_segment.clear();
				points.clear();
				indices.clear();
				points_colors.clear();
				segment_colors.clear();
				mesh_colors.clear();
			}
			Context() { ; }
			~Context() { clear(); }
		};
		// --------------------------------------------		
		// 
		// --------------------------------------------
		class RendererEasy3d : public Renderer
		{
		public:
			RendererEasy3d();
			RendererEasy3d::~RendererEasy3d();
		

		private:
			// override
			void group_begin (const std::string &name);
			// override
			void group_end ();
			// override
			void draw_point(const math::Vector2& p, const Rgb& rgb, enum PointStyle s);
			// override
			void draw_segment(const math::VectorPair2& l, const Rgb& rgb);
			// override
			void draw_point(const math::Vector3& p, const Rgb& rgb, enum PointStyle s);
			// override
			void draw_segment(const math::VectorPair3& l, const Rgb& rgb);
			// override
			void draw_polygon(const math::Vector3* array, unsigned int count, const Rgb& rgb, bool filled, bool closed);
			// override
			void draw_triangle(const math::Triangle<3>& t, const Rgb& rgb);
			// override
			void draw_triangle(const math::Triangle<3>& t,const math::Triangle<3>& gradient, const Rgb& rgb);
			// override
			void draw_text(const math::Vector3& pos, const math::Vector3& dir,
				const std::string& str, TextAlignMask a, int size,
				const Rgb& rgb);

			// override
			void draw_text(const math::Vector2& pos, const math::Vector2& dir,
				const std::string& str, TextAlignMask a, int size,
				const Rgb& rgb);
			
		};

	}
}

#endif

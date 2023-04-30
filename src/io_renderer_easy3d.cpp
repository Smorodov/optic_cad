
#include "renderer_easy3d.hpp"
#include <goptical/core/math/transform.hpp>
#include <goptical/core/math/triangle.hpp>

namespace goptical
{

	namespace io
	{
		RendererEasy3d::RendererEasy3d ()			
		{
			user_data=new Context();
		}

		RendererEasy3d::~RendererEasy3d()
		{
			delete user_data;
		}

		void RendererEasy3d::group_begin (const std::string &name)
		{
			auto ctx=static_cast<Context*>(user_data);
			auto mesh=new easy3d::SurfaceMesh();						
			ctx->meshes.push_back(mesh);
			ctx->mesh_colors.push_back(easy3d::vec4(1,1,1,1));
		}

		void RendererEasy3d::group_end ()
		{
			auto ctx=static_cast<Context*>(user_data);
			if(ctx->meshes.back()->empty())
			{
				delete ctx->meshes.back();
				ctx->meshes.pop_back();
				ctx->mesh_colors.pop_back();
			}else
			{

			}
		}

		void RendererEasy3d::draw_point (const math::Vector2 &p, const Rgb &rgb, enum PointStyle s)
		{
			auto ctx=static_cast<Context*>(user_data);
			ctx->points_colors.push_back(easy3d::vec4(rgb.r,rgb.g,rgb.b,rgb.a));
			ctx->points.push_back(easy3d::vec3(p.x(),p.y(),0) );
		}

		void RendererEasy3d::draw_segment (const math::VectorPair2 &l, const Rgb &rgb)
		{
			auto ctx=static_cast<Context*>(user_data);
			ctx->segment_colors.push_back(easy3d::vec4(rgb.r,rgb.g,rgb.b,rgb.a));
			ctx->points_segment.push_back(easy3d::vec3(l[0].x(),l[0].y(),0 ));
			ctx->points_segment.push_back(easy3d::vec3(l[1].x(),l[1].y(),0 ));
			auto sz=ctx->points_segment.size();
			ctx->indices.push_back(sz-2);
			ctx->indices.push_back(sz-1);
		}

		void RendererEasy3d::draw_point (const math::Vector3 &p, const Rgb &rgb, enum PointStyle s)
		{
			auto ctx=static_cast<Context*>(user_data);
			ctx->points_colors.push_back(easy3d::vec4(rgb.r,rgb.g,rgb.b,rgb.a));
			ctx->points.push_back(easy3d::vec3(p.x(),p.y(),p.z() ));
		}

		void RendererEasy3d::draw_segment (const math::VectorPair3 &l, const Rgb &rgb)
		{
			auto ctx=static_cast<Context*>(user_data);
			ctx->segment_colors.push_back(easy3d::vec4(rgb.r,rgb.g,rgb.b,rgb.a));

			ctx->points_segment.push_back(easy3d::vec3(l[0].x(),l[0].y(),l[0].z() ));
			ctx->points_segment.push_back(easy3d::vec3(l[1].x(),l[1].y(),l[1].z() ));
			auto sz=ctx->points_segment.size();
			ctx->indices.push_back(sz-2);
			ctx->indices.push_back(sz-1);			
		}

		void RendererEasy3d::draw_text (const math::Vector2 &c, const math::Vector2 &dir,
		                           const std::string &str, TextAlignMask a, int size,
		                           const Rgb &rgb)
		{
			auto ctx=static_cast<Context*>(user_data);			
		}

		void RendererEasy3d::draw_text (const math::Vector3 &c, const math::Vector3 &dir,
		                           const std::string &str, TextAlignMask a, int size,
		                           const Rgb &rgb)
		{
			auto ctx=static_cast<Context*>(user_data);
			
		}

		void RendererEasy3d::draw_polygon (const math::Vector3 *array, unsigned int count, const Rgb &rgb, bool filled, bool closed)
		{
			auto ctx=static_cast<Context*>(user_data);
			if (count < 3)
			{
				return;
			}
			if (filled)
			{
				
			}
			else
			{

			}
		}

		void RendererEasy3d::draw_triangle (const math::Triangle<3> &t, const Rgb &rgb)
		{
			auto ctx=static_cast<Context*>(user_data);
		
			ctx->mesh_colors.back()=easy3d::vec4(rgb.r,rgb.g,rgb.b,rgb.a)
				;
			easy3d::SurfaceMesh::Vertex v0 = ctx->meshes.back()->add_vertex(easy3d::vec3(t[0].x(), t[0].y(), t[0].z()));
			easy3d::SurfaceMesh::Vertex v1 = ctx->meshes.back()->add_vertex(easy3d::vec3(t[1].x(), t[1].y(), t[1].z()));
			easy3d::SurfaceMesh::Vertex v3 = ctx->meshes.back()->add_vertex(easy3d::vec3(t[2].x(), t[2].y(), t[2].z()));
				
			// Add faces
			ctx->meshes.back()->add_triangle(v0, v1, v3);				
			
		}

		void RendererEasy3d::draw_triangle (const math::Triangle<3> &t,
		                               const math::Triangle<3> &gradient,
		                               const Rgb &rgb)
		{
			auto ctx=static_cast<Context*>(user_data);
			
			ctx->mesh_colors.back()=easy3d::vec4(rgb.r,rgb.g,rgb.b,rgb.a);

			easy3d::SurfaceMesh::Vertex v0 = ctx->meshes.back()->add_vertex(easy3d::vec3(t[0].x(), t[0].y(), t[0].z()));
			easy3d::SurfaceMesh::Vertex v1 = ctx->meshes.back()->add_vertex(easy3d::vec3(t[1].x(), t[1].y(), t[1].z()));
			easy3d::SurfaceMesh::Vertex v3 = ctx->meshes.back()->add_vertex(easy3d::vec3(t[2].x(), t[2].y(), t[2].z()));
				
			// Add faces
			ctx->meshes.back()->add_triangle(v0, v1, v3);				
		}
		
	}
}

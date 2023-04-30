#include "viewer.h"

#include <easy3d/util/file_system.h>

#include <easy3d/core/point_cloud.h>
#include <easy3d/core/surface_mesh.h>
#include <easy3d/renderer/text_renderer.h>
#include <easy3d/renderer/camera.h>
#include <easy3d/renderer/camera.h>

#include <3rd_party/imgui/misc/fonts/imgui_fonts_droid_sans.h>
#include <3rd_party/imgui/imgui.h>
#include <3rd_party/imgui/backends/imgui_impl_glfw.h>
#include <3rd_party/imgui/backends/imgui_impl_opengl3.h>
#include <3rd_party/glfw/include/GLFW/glfw3.h>

#include <easy3d/renderer/drawable_lines.h>
#include <easy3d/renderer/drawable_points.h>
#include <easy3d/renderer/drawable_triangles.h>
#include <easy3d/renderer/renderer.h>

namespace easy3d {

	ImGuiContext* ViewerImGui::context_ = nullptr;

	ViewerImGui::ViewerImGui(

		const std::string& title /* = "Easy3D ImGui Viewer" */,
		int samples /* = 4 */,
		int gl_major /* = 3 */,
		int gl_minor /* = 2 */,
		bool full_screen /* = false */,
		bool resizable /* = true */,
		int depth_bits /* = 24 */,
		int stencil_bits /* = 8 */,
		int width /* = 960 */,
		int height /* = 800 */
	) : Viewer(title, samples, gl_major, gl_minor, full_screen, resizable, depth_bits, stencil_bits, width, height)
	{
#if defined(_WIN32) || defined(MSVC)
		// Liangliang: the internal glfw won't be shared across dll boundaries (But seems ok on mac. That is weird!)
		glfwInit();
#endif
	}


	ViewerImGui::~ViewerImGui()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();

		ImGui::DestroyContext(context_);

		// Not needed: it will be called in the destructor of the base class
		//Viewer::cleanup();

#if defined(_WIN32) || defined(MSVC)
		// Liangliang: the internal glfw won't be shared across dll boundaries (But seems ok on mac. That is weird!)
		glfwTerminate();
#endif
	}


	void ViewerImGui::init()
	{
		Viewer::init();

		if (!context_) {
			// Setup ImGui binding
			IMGUI_CHECKVERSION();

			context_ = ImGui::CreateContext();
			Viewer::camera()->setType(Camera::Type::ORTHOGRAPHIC);
			const char* glsl_version = "#version 150";
			ImGui_ImplGlfw_InitForOpenGL(window_, true);
			ImGui_ImplOpenGL3_Init(glsl_version);
			ImGuiIO& io = ImGui::GetIO();
			io.WantCaptureKeyboard = true;
			io.WantTextInput = true;
			io.IniFilename = nullptr;
			ImGui::StyleColorsDark();
			ImGuiStyle& style = ImGui::GetStyle();
			style.FrameRounding = 5.0f;

			// load font
			reload_font();

			Viewer::set_background_color(vec4(0.2, 0.2, 0.3, 1));			
			optical_system = std::make_shared<Optical_system>();
			auto meshes = ((goptical::io::Context*)optical_system->renderer->user_data)->meshes;
			
			int ind=0;
			auto mesh_colors = ((goptical::io::Context*)optical_system->renderer->user_data)->mesh_colors;
			auto poimts_colors = ((goptical::io::Context*)optical_system->renderer->user_data)->points_colors;
			
			for (auto m : meshes)
			{
				Viewer::add_model(m, true);
				auto f=m->renderer()->get_triangles_drawable("faces");
				f->set_uniform_coloring(mesh_colors[ind]);
				f->set_back_color(mesh_colors[ind]);

				f->set_lighting_two_sides(true);
				++ind;

			}
			//fit_screen(meshes[0]);
			
// /*		
			//-------------------------------------------------------------
			// Create a PointsDrawable to visualize the vertices of the "bunny".
			// Only the vertex positions have to be sent to the GPU for visualization.
			auto vertices = new easy3d::PointsDrawable("vertices");
			// Upload the vertex positions to the GPU.
			auto points = ((goptical::io::Context*)optical_system->renderer->user_data)->points;
			vertices->update_vertex_buffer(points);
			// Set a color for the vertices (here we want a red color).
			vertices->set_uniform_coloring(vec4(1.0f, 0.0f, 0.0f, 1.0f));  // RBGA
			
			// Three options are available for visualizing points:
			//      - PLAIN: plain points (i.e., each point is a square on the screen);
			//      - SPHERE: each point is visualized a sphere;
			//      - SURFEL: each point is visualized an oriented disk.
			// In this example, let's render the vertices as spheres.
			vertices->set_impostor_type(PointsDrawable::SPHERE);
			// Set the vertices size (here 10 pixels).
			vertices->set_point_size(5);
			// Add the drawable to the viewer
			Viewer::add_drawable(vertices);


			auto indices = ((goptical::io::Context*)optical_system->renderer->user_data)->indices;
			int nLines = indices.size() / 2;
			auto points_segment = ((goptical::io::Context*)optical_system->renderer->user_data)->points_segment;
			auto segment_colors = ((goptical::io::Context*)optical_system->renderer->user_data)->segment_colors;
			for (int i = 0; i < nLines; ++i)
			{
				auto line_drawable = new LinesDrawable("line" + std::to_string(i));
				std::vector<easy3d::vec3> vert;
				std::vector<unsigned int> ind;
				vert.push_back(points_segment[indices[2 * i]]);
				vert.push_back(points_segment[indices[2 * i + 1]]);
				ind.push_back(0);
				ind.push_back(1);

				// Upload the vertex positions
				line_drawable->update_vertex_buffer(vert);
				// Upload the vertex indices of the bounding box to the GPU.
				line_drawable->update_element_buffer(ind);
				// Set a color for the edges of the bounding box (here we want a blue color).
				line_drawable->set_uniform_coloring(segment_colors[i]);    // r, g, b, a
				// Set the width of the edges (here 5 pixels).
				line_drawable->set_line_width(0.5f);
				// Add the drawable to the viewer
				Viewer::add_drawable(line_drawable);
			}
	//	*/
		}
	
	}


	float ViewerImGui::pixel_ratio() {
		// Computes pixel ratio for hidpi devices
		int fw = framebuffer_width();
		int vw = width();
		return static_cast<float>(fw) / static_cast<float>(vw);
	}


	void ViewerImGui::reload_font(int font_size)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.Fonts->Clear();
		io.Fonts->AddFontFromMemoryCompressedTTF(droid_sans_compressed_data, droid_sans_compressed_size, static_cast<float>(font_size) * dpi_scaling());
		io.FontGlobalScale = 1.0f / pixel_ratio();
		ImGui_ImplOpenGL3_DestroyDeviceObjects();
	}


	void ViewerImGui::post_resize(int w, int h) {		
		Viewer::post_resize(w, h);
		if (context_) {
			ImGui::GetIO().DisplaySize.x = float(w);
			ImGui::GetIO().DisplaySize.y = float(h);
		}
	}


	bool ViewerImGui::callback_event_cursor_pos(double x, double y) {
		if (ImGui::GetIO().WantCaptureMouse)
			return true;
		else
			return Viewer::callback_event_cursor_pos(x, y);
	}


	bool ViewerImGui::callback_event_mouse_button(int button, int action, int modifiers) {
		if (ImGui::GetIO().WantCaptureMouse)
			return true;
		else
			return Viewer::callback_event_mouse_button(button, action, modifiers);
	}


	bool ViewerImGui::callback_event_keyboard(int key, int action, int modifiers) {
		if (ImGui::GetIO().WantCaptureKeyboard)
			return true;
		else
			return Viewer::callback_event_keyboard(key, action, modifiers);
	}


	bool ViewerImGui::callback_event_character(unsigned int codepoint) {
		if (ImGui::GetIO().WantCaptureKeyboard)
			return true;
		else
			return Viewer::callback_event_character(codepoint);
	}


	bool ViewerImGui::callback_event_scroll(double dx, double dy) {
		if (ImGui::GetIO().WantCaptureMouse)
			return true;
		else
			return Viewer::callback_event_scroll(dx, dy);
	}

	
	void ViewerImGui::pre_draw() {
		
		// initial fit
		static bool first=1;
		if(first)
		{
			auto bb=optical_system->opt_sys->get_bounding_box();
			Viewer::camera()->fitBoundingBox(easy3d::vec3(bb.x0(),bb.y0(),bb.z0()),easy3d::vec3(bb.x1(),bb.y1(),bb.z1()));
		Viewer::camera()->setPivotPoint(easy3d::vec3(0,0,0));
		first=0;
		}
		ImGui_ImplGlfw_NewFrame();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		Viewer::pre_draw();
	}


	void ViewerImGui::post_draw() {
		static bool show_about = false;
		if (show_about) {
			ImGui::SetNextWindowPos(ImVec2(static_cast<float>(width()) * 0.5f, static_cast<float>(height()) * 0.5f), ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
			ImGui::Begin("About Easy3D ImGui Viewer", &show_about, ImGuiWindowFlags_NoResize);
			ImGui::Text("This viewer shows how to use ImGui for GUI creation and event handling");
			ImGui::Separator();
			ImGui::Text(
				"\n"
				"Liangliang Nan\n"
				"liangliang.nan@gmail.com\n"
				"https://3d.bk.tudelft.nl/liangliang/\n"
			);
			ImGui::End();
		}

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 8));
		if (ImGui::BeginMainMenuBar())
		{
			draw_menu_file();
			draw_menu_view();

			if (ImGui::BeginMenu("Help")) {
				ImGui::MenuItem("About", nullptr, &show_about);
				ImGui::EndMenu();
			}
			menu_height_ = ImGui::GetWindowHeight();
			ImGui::EndMainMenuBar();
		}
		ImGui::PopStyleVar();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// TODO: a workaround to draw the Easy3D logo at a different location (due to the menu bar)
		auto texter = texter_;
		texter_ = nullptr;
		Viewer::post_draw();
		texter_ = texter;

		// draw Easy3D logo
		if (texter_) {
			const float font_size = 15.0f;
			const float offset_x = (width() - texter_->string_width("GOptical", font_size) - 20.0f) * dpi_scaling();
			const float offset_y = (20.0f + menu_height_) * dpi_scaling();
			texter_->draw("GOptical", offset_x, offset_y, font_size, 0, vec3(1, 1, 1));
		}
	}


	void ViewerImGui::draw_menu_file() {
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Open", "Ctrl+O"))
				open();
			if (ImGui::MenuItem("Save As...", "Ctrl+S"))
				save();

			ImGui::Separator();
			if (ImGui::MenuItem("Quit", "Alt+F4"))
				glfwSetWindowShouldClose(window_, GLFW_TRUE);

			ImGui::EndMenu();
		}
	}


	void ViewerImGui::draw_menu_view() {
		if (ImGui::BeginMenu("View"))
		{
			if (ImGui::MenuItem("Snapshot", nullptr))
				snapshot();

			ImGui::EndMenu();
		}
	}
}

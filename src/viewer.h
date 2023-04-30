#ifndef EASY3D_TUTORIAL_VIEWER_IMGUI_H
#define EASY3D_TUTORIAL_VIEWER_IMGUI_H

#include "optical_system.h"
#include <easy3d/viewer/viewer.h>

#include "renderer_easy3d.hpp"


// A very good tutorial for imgui:
// https://eliasdaler.github.io/using-imgui-with-sfml-pt1/
// https://eliasdaler.github.io/using-imgui-with-sfml-pt2/


struct ImGuiContext;


namespace easy3d {

    class ViewerImGui : public Viewer
	{
	public:
		std::shared_ptr<Optical_system> optical_system;
        /**
         * @brief Constructor
         * @param title The window title of the viewer, which can be changed by calling set_title() after construction.
         * @param samples The number of samples for multisample antialiasing
         * @param gl_major/gl_minor The OpenGL version to request. The created context will be
         *        compatible with the requested version (if the context creation succeeded).
         * @param full_screen Do you want the viewer to be fullscreen?
         * @param resizable Whether the viewer will be resizable by the user.
         * @param depth_bits The desired bit depths of the depth component of the default framebuffer.
         * @param stencil_bits The desired bit depths of the stencil component of the default framebuffer.
         * @param width The width of the viewer, which can be changed by calling resize() after construction.
         * @param height The height of the viewer, which can be changed by calling resize() after construction.
         */
        explicit ViewerImGui(
            const std::string& title = "Easy3D ViewerImGui",
			int samples = 4,
            int gl_major = 3,   // must >= 3
            int gl_minor = 2,   // must >= 2
			bool full_screen = false,
			bool resizable = true,
			int depth_bits = 24,
			int stencil_bits = 8,
            int width = 800,
            int height = 600
		);

        /**
         * @brief The destructor of the Viewer.
         */
        ~ViewerImGui() override;

	protected:

		// imgui plugins
		void init() override;

		// draw the widgets
		void pre_draw() override;

		//  the widgets
		void post_draw() override;

		void post_resize(int w, int h) override;

		bool callback_event_cursor_pos(double x, double y) override;
		bool callback_event_mouse_button(int button, int action, int modifiers) override;
		bool callback_event_keyboard(int key, int action, int modifiers) override;
		bool callback_event_character(unsigned int codepoint) override;
		bool callback_event_scroll(double dx, double dy) override;

        void draw_menu_file();
        void draw_menu_view();

	protected:
        // Ratio between the framebuffer size and the window size.
        // May be different from the DPI scaling!
		float pixel_ratio();

		float widget_scaling() { return dpi_scaling() / pixel_ratio(); }

		// We don't need a per-window font. So this function is static
		void  reload_font(int font_size = 16);

	protected:
		// Single global context by default, but can be overridden by the user
		static ImGuiContext *	context_;

		float menu_height_;
	};

}

#endif	// EASY3D_TUTORIAL_VIEWER_IMGUI_H

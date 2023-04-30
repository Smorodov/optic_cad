set(imgui_HEADERS
        imgui.h
        backends/imgui_impl_glfw.h
        backends/imgui_impl_opengl3.h
        backends/imgui_impl_opengl3_loader.h
        )

set(imgui_SOURCES
        imgui.cpp
        imgui_draw.cpp
        imgui_widgets.cpp
        imgui_tables.cpp
        backends/imgui_impl_glfw.cpp
        backends/imgui_impl_opengl3.cpp
        )

add_library(imgui STATIC "${imgui_SOURCES}" "${imgui_HEADERS}")
target_include_directories(imgui PUBLIC        
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/glfw/include
        )
target_link_libraries(imgui PRIVATE 3rd_glfw)
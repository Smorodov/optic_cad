cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

project(optic_cad)

    FIND_PACKAGE(OpenMP)
    if(OPENMP_FOUND)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
    endif()
    add_definitions(-DEasy3D_RESOURCE_DIR="resources")
    add_subdirectory(glfw)
    add_subdirectory(imgui)
    add_subdirectory(goptical)
find_package(Easy3D)

include_directories("${Easy3D_LIBRARY_DIRS}/../include")
include_directories(${Easy3D_INCLUDE_DIRS})
include_directories(${Easy3D_INCLUDE_DIRS}/3rd_party/imgui)
include_directories(main)
include_directories(goptical/include)

include_directories(src)

set(SOURCES
src/main.cpp
src/viewer.cpp
src/io_renderer_easy3d.cpp
src/optical_system.cpp
)

set(HEADERS
src/viewer.h
src/renderer_easy3d.hpp
src/optical_system.h
)
add_definitions(-D_USE_MATH_DEFINES -DNOMINMAX)
SOURCE_GROUP("Source Files" FILES ${SOURCES})
SOURCE_GROUP("Header Files" FILES ${HEADERS})
# -----------------------------
#
# -----------------------------
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} 
"${Easy3D_LIBRARY_DIRS}/*.lib"
optimized "${Easy3D_LIBRARY_DIRS}/Release/*.lib"
debug "${Easy3D_LIBRARY_DIRS}/Debug/*.lib"
imgui
goptical_static
)
message("libraries:" "${Easy3D_LIBRARY_DIRS}/*.lib")

# -----------------------------
set_target_properties( ${PROJECT_NAME} PROPERTIES  VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)

file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_algo.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_core.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_fileio.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_gui.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_kdtree.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_renderer.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_util.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_viewer.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Release)


file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_algo_d.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_core_d.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_fileio_d.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_gui_d.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_kdtree_d.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_renderer_d.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_util_d.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
file(COPY ${Easy3D_LIBRARY_DIRS}/../bin/easy3d_viewer_d.dll  DESTINATION ${CMAKE_SOURCE_DIR}/build/Debug)
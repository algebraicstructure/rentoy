cmake_minimum_required(VERSION 4.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GLFW_BUILD_WAYLAND ON)
set(GLFW_BUILD_X11 OFF)

project(rentoy)

add_executable(rentoy src/main.cpp src/gl.c src/window.cpp)

add_subdirectory(lib/glfw)

target_link_libraries(rentoy
    PRIVATE
    glfw
)

target_include_directories(rentoy
    PRIVATE
    include
)

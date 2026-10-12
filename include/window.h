#pragma once

// clang-format off
#define GLFW_INCLUDE_NONE
#include "glad/gl.h" // IWYU pragma: keep
#include "GLFW/glfw3.h"
// clang-format on

struct Window {
    int width;
    int height;
    char const* title;
    GLFWwindow* context;
};

void processInput(GLFWwindow* context);
void initializeGLFW();
struct Window createWindow(int width, int height, char const* title);
void destroyWindow(struct Window& window);

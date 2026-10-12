#include <cstdio>
#include <iostream>

#include "window.h"

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void framebuffer_size_callback(GLFWwindow* context, int width, int height) {
    glViewport(0, 0, width, height);
}
static void registerCallbacks(GLFWwindow* context) {
    glfwSetFramebufferSizeCallback(context, framebuffer_size_callback);
}

void processInput(GLFWwindow* context) {
    if (glfwGetKey(context, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(context, true);
}

void initializeGLFW() {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    std::cout << "Initialized GLFW" << std::endl;
}

struct Window createWindow(int width, int height, char const* title) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* context = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!context) {
        std::cout << "Failed to create OpenGL context" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    std::cout << "Created OpenGL context\n";
    glfwMakeContextCurrent(context);
    registerCallbacks(context);

    if (!gladLoadGL(glfwGetProcAddress)) {
        std::cout << "Failed to load GLAD" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    int viewport_width, viewport_height;
    glfwGetFramebufferSize(context, &viewport_width, &viewport_height);
    glViewport(0, 0, viewport_width, viewport_height);

    struct Window window;
    window.width = width;
    window.height = height;
    window.context = context;

    return window;
}

void destroyWindow(struct Window& window) {
    glfwDestroyWindow(window.context);
    window.context = NULL;
}

#include <cstdlib>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include "glad/gl.h"
#include "GLFW/glfw3.h"

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}


int main()
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    std::cout << "Initialized GLFW\n";

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* context = glfwCreateWindow(1920, 1080, "Rentoy", NULL, NULL);
    if (!context) {
        glfwTerminate();
        std::cout << "Failed to create OpenGL context\n";
        exit(EXIT_FAILURE);
    }
    std::cout << "Created OpenGL context\n";

    glfwMakeContextCurrent(context);
    gladLoadGL(glfwGetProcAddress);

    int width, height;
    glfwGetFramebufferSize(context, &width, &height);
    glViewport(0, 0, width, height);

    double start_time, end_time = glfwGetTime();
    double frame_time = 0.0;

    while (!glfwWindowShouldClose(context)) {
        start_time = glfwGetTime();
        glfwSwapBuffers(context);
        end_time = glfwGetTime();
        frame_time = end_time - start_time;
        std::cout << "Frametime = " << frame_time << std::endl;
    }

    std::cout << "Destroying context and terminating GLFW\n";
    glfwDestroyWindow(context);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

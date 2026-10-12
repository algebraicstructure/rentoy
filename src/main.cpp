#include <cstdlib>
#include <iostream>

// clang-format off
#define GLFW_INCLUDE_NONE
#include "glad/gl.h"
#include "GLFW/glfw3.h"
// clang-format on

#include "window.h"

int main() {
    int width = 1920;
    int height = 1080;
    char const* title = "Rentoy";
    struct Window window = createWindow(width, height, title);

    double start_time, end_time = glfwGetTime();
    double frame_time = 0.0;

    while (!glfwWindowShouldClose(window.context)) {
        start_time = glfwGetTime();
        processInput(window.context);

        // rendering commands
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // check and call events and swap the buffers
        glfwSwapBuffers(window.context);
        glfwPollEvents();

        end_time = glfwGetTime();
        frame_time = end_time - start_time;
        std::cout << "Frametime = " << frame_time << std::endl;
    }

    destroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

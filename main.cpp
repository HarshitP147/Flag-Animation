#include <iostream>

// library for window creation and manipulation
#include <GLFW/glfw3.h>

// library responsible for the mathematical implementation behind open gl
// this is the library that contains all the tools like vec3, vec4 and mat4 that are required
#include <glm/glm.hpp>

GLFWwindow *window; // declare a window pointer in the global scope

class Triangle{
    public:
        Triangle(){

        }

        ~Triangle(){

        }
};

int main()
{
    std::cout << "Initializing a new window" << std::endl;

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize a window" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For MacOS
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(700, 400, "Main", NULL, NULL);
    if (window == nullptr || window == NULL)
    {
        std::cerr << "Failed to create a window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    // glfwSetKeyCallback(window, key_callback);

    glClearColor(0.2f, 0.2f, 0.25f, 0.0f);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window));

    glfwTerminate();

    return 0;
}
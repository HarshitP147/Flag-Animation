#include <iostream>
#include <vector>

// library for necessary opengl functions to load at the window
#include <glad/gl.h>

// library responsible for the mathematical implementation behind open gl
// this is the library that contains all the tools like vec3, vec4 and mat4 that
// are required
#include <glm/glm.hpp>

// library for window creation and manipulation
#include <GLFW/glfw3.h>

#include "main.h"

GLFWwindow *window; // declare a window pointer in the global scope

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        std::cout << "Space key is pressed." << std::endl;
    }

    if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        std::cout << "A key is pressed." << std::endl;
    }

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

// GLuint LoadShadersFromString(std::string VertexShaderCode, std::string FragmentShaderCode) {
//     // Create the shaders
//     GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
//     GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

//     GLint Result = GL_FALSE;
//     int InfoLogLength;

//     // Compile Vertex Shader
//     printf("Compiling vertex shader\n");
//     char const *VertexSourcePointer = VertexShaderCode.c_str();
//     glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
//     glCompileShader(VertexShaderID);

//     // Check Vertex Shader
//     glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
//     glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
//     if (InfoLogLength > 0) {
//         std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
//         glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
//         printf("%s\n", &VertexShaderErrorMessage[0]);
//         return 0;
//     }

//     // Compile Fragment Shader
//     printf("Compiling fragment shader\n");
//     char const *FragmentSourcePointer = FragmentShaderCode.c_str();
//     glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
//     glCompileShader(FragmentShaderID);

//     // Check Fragment Shader
//     glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
//     glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
//     if (InfoLogLength > 0) {
//         std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
//         glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
//         printf("%s\n", &FragmentShaderErrorMessage[0]);
//         return 0;
//     }

//     // Link the program
//     printf("Linking program\n");
//     GLuint ProgramID = glCreateProgram();
//     glAttachShader(ProgramID, VertexShaderID);
//     glAttachShader(ProgramID, FragmentShaderID);
//     glLinkProgram(ProgramID);

//     // Check the program
//     glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
//     glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
//     if (InfoLogLength > 0) {
//         std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
//         glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
//         printf("%s\n", &ProgramErrorMessage[0]);
//         return 0;
//     }

//     glDetachShader(ProgramID, VertexShaderID);
//     glDetachShader(ProgramID, FragmentShaderID);

//     glDeleteShader(VertexShaderID);
//     glDeleteShader(FragmentShaderID);

//     return ProgramID;
// }

int main() {
    std::cout << "Initializing a new window" << std::endl;

    if (!glfwInit()) {
        std::cerr << "Failed to initialize a window" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For MacOS
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 450, "Main", NULL, NULL);
    if (window == nullptr || window == NULL) {
        std::cerr << "Failed to create a window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetKeyCallback(window, key_callback);

    // Initialize the actual objects to render
    // const GLfloat vertex_buffer_data[] = {
    //     // x,y,z,repeat
    //     // side 1
    //     0.0f, 0.0f, 0.0f,
    //     0.0f, 1.0f, 0.0f,
    //     0.0f, 1.0f, 1.0f,
    //     0.0f, 0.0f, 1.0f};

    // const GLfloat color_buffer_data[] = {
    //     // r,g,b,repeat

    //     // each 3 pairs correspond to each vertex points which will be coloured the corresponding values as mentioned below
    //     // side 1
    //     1.0f, 0.0f, 0.0f,
    //     1.0f, 0.0f, 0.0f,
    //     1.0f, 0.0f, 0.0f,
    //     1.0f, 0.0f, 0.0f};

    // const GLint index_buffer_data[] = {
    //     // the index buffer data helps in easier division of triangle meshes
    //     // it specifies which points are to be optimized for triangle corners so that repitition is avoided
    //     0, 1, 2,
    //     0, 2, 3};



    // GLuint program_id;
    // // program_id = LoadShadersFromString(vertex_shader, fragment_shader);
    // if(program_id==0){
    //     std::cerr << "Program ID value 0" << std::endl;
    // }

    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        std::cout << "This is not working perfectly" << std::endl;

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window));

    // Clear the memory from the GPU
    // glDeleteProgram(program_id);

    glfwTerminate();

    return 0;
}
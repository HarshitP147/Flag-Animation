#include <string>

static std::string vertex_shader = R"(
#version 330 core

layout(location=0) in vec3 position;

void main(){
    gl_Position.xyz = position;
    gl_Position.w = 1.0;
}
)";

static std::string fragment_shader = R"(
#version 330 core

layout(location=0) in vec3 position;

void main(){
    gl_Position.xyz = position;
    gl_Position.w = 1.0;
}
)";
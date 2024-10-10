#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/gl.h>
#include <string>


GLuint LoadShadersFromString(std::string VertexShaderCode, std::string FragmentShaderCode);


#endif
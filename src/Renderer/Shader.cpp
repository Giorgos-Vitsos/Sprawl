#include "Shader.h"
#include <glad/glad.h>
#include <iostream>
#include <vector>

Shader::Shader(const std::string &vertexCode,const std::string &fragmentCode){
    m_ID=CreateShaderProgram(vertexCode,fragmentCode);
}

Shader::~Shader(){
    glDeleteProgram(m_ID);
}

void Shader::Bind() const{
    glUseProgram(m_ID);
}

void Shader::Unbind() const{
    glUseProgram(0);
}

unsigned int Shader::CompileShader(unsigned int type,const std::string& sourceCode){
    unsigned int id=glCreateShader(type);
    const char* src=sourceCode.c_str();
    glShaderSource(id,1,&src,nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        
        std::vector<char> message(length);
        glGetShaderInfoLog(id, length, &length, message.data());
        
        glDeleteShader(id);
        
        std::string shaderType = (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment");
        throw std::runtime_error("Failed to compile " + shaderType + " shader!\n" + message.data());
    }

    return id;
}

unsigned int Shader::CreateShaderProgram(const std::string &vertexCode,const std::string &fragmentCode){
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexCode);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentCode);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    int result;
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> message(length);
        glGetProgramInfoLog(program, length, &length, message.data());
        
        glDeleteProgram(program);
        glDeleteShader(vs);
        glDeleteShader(fs);
        
        throw std::runtime_error("Failed to link shader program!\n" + std::string(message.data()));
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}
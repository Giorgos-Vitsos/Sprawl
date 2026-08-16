#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

Shader::Shader(const std::string &vertexPath,const std::string &fragmentPath){
    std::string vertexCode=ReadFile(vertexPath);
    std::string fragmentCode=ReadFile(fragmentPath);
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
    if (result == GL_FALSE) {//if it failed we build report msg
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

std::string Shader::ReadFile(const std::string &filePath){
    std::ifstream stream(filePath);
    if(!stream.is_open()){
        throw std::runtime_error("Failed to open Shader file: "+ filePath);
    }
    std::stringstream buffer;
    buffer<<stream.rdbuf();
    return buffer.str();
}

int Shader::GetUniformLoc(const std::string &name){
    return glGetUniformLocation(m_ID,name.c_str());
}

void Shader::SetUniformMat4f(const std::string &name,const glm::mat4 &matrix){
    Bind();
    int location=GetUniformLoc(name);
    if(location==-1){
        std::cout<<"Warning: uniform "<<name<<"couldnt be found"<<std::endl;
    }
    glUniformMatrix4fv(location,1,GL_FALSE,glm::value_ptr(matrix));
}
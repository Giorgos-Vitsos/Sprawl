#include "OpenGLDebug.h"
#include <iostream>


void OpenGLDebug::Init(){
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(DebugCallback,nullptr);
    glDebugMessageControl(GL_DONT_CARE,GL_DONT_CARE,GL_DONT_CARE,0,nullptr,GL_TRUE);
    glDebugMessageControl(GL_DONT_CARE,GL_DONT_CARE,GL_DEBUG_SEVERITY_NOTIFICATION,0,nullptr,GL_FALSE);
}

void OpenGLDebug::DebugCallback(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam){
    std::string color;
    switch (severity)
    {
    case GL_DEBUG_SEVERITY_MEDIUM:
        color="\033[33m";
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        color="\033[31m";
        break;
    default:
        color="\033[37m";
        break;
    }
    std::cerr<<"\n"<<color<<"Debug: "<<message<<"\033[0m"<<std::endl;
}
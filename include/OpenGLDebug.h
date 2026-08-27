#pragma once
#include <glad/glad.h>

class OpenGLDebug{
    public:
        static void Init();
    private:
        static void APIENTRY DebugCallback(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
};
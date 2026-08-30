#pragma once
#include <glad/glad.h>

/**
 * @brief Main debugging class during runtime
 * 
 * Responsible for announcing errors and warning in the runtime.
 */
class OpenGLDebug{
    public:
        /**
        * @brief Enables GL_DEBUG_OUTPUT and maximum level of 
        * debug messages. Also, filters normal notifications.
        */
        static void Init();
        
        /**
        * @brief Constructor is disable because class is static.
        */
        OpenGLDebug()=delete;
    private:
        /**
        * @brief Splits the error in specific colour-coded categories
        * based on severity. Then reports them via the terminal.
        * 
        * @param source The source of the error.
        * @param type The type of error.
        * @param id The error code.
        * @param severity If its warning or high risk.
        * @param length The size of the error message.
        * @param message The description of the error.
        * @param userParam Null.
        */
        static void APIENTRY DebugCallback(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
};
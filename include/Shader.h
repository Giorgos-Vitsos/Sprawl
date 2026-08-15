#pragma once
#include <string>

class Shader{
    public:
        Shader(const std::string &vertexCode,const std::string &fragmentCode);
        ~Shader();
        void Bind() const;
        void Unbind() const;
    private:
        unsigned int m_ID;
        unsigned int CompileShader(unsigned int type,const std::string& sourceCode);
        unsigned int CreateShaderProgram(const std::string &vertexCode,const std::string &fragmentCode);
};
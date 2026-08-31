#pragma once
#include <string>
#include <glm/glm.hpp>
#include <unordered_map>
/**
 * @brief Manages an OpenGL shader program.
 *
 * Responsible for loading raw shader code from disk, compiling the
 * vertex and fragment shaders, and linking them into a single program.
 */
class Shader
{
public:
    /**
     * @brief Creates and compiles a shader program.
     *
     * The provided vertex and fragment shader source files are
     * compiled independently and then linked into a single
     * executable shader program that can be used by the GPU.
     *
     * @param vertexPath Path to the vertex shader source file.
     * @param fragmentPath Path to the fragment shader source file.
     */
    Shader(const std::string &vertexPath, const std::string &fragmentPath);

    /**
     * @brief Destroys the shader program and frees GPU resources.
     */
    ~Shader();

    /**
     * @brief Binds the shader program for upcoming render calls.
     */
    void Bind() const;

    /**
     * @brief Unbinds the current shader program.
     */
    void Unbind() const;

    /**
     * @brief Sets uniform with type mat4.
     * 
     * @param name The uniform to set.
     * @param matrix The value to set.
     */
    void SetUniformMat4f(const std::string &name,const glm::mat4 &matrix);

    /**
     * @brief Sets uniform with type int.
     * 
     * @param name The uniform to set.
     * @param value The value to set.
     */
    void SetUniform1i(const std::string& name,const int value);

    /**
     * @brief Sets uniform with type float.
     * 
     * @param name The uniform to set.
     * @param value The value to set.
     */
    void SetUniform1f(const std::string& name,const float value);

    /**
     * @brief Sets uniform with type vec3.
     * 
     * @param name The uniform to set.
     * @param value The value to set.
     */
    void SetUniform3f(const std::string& name,const glm::vec3 &value);

    /**
     * @brief Sets uniform with type vec4.
     * 
     * @param name The uniform to set.
     * @param value The value to set.
     */
    void SetUniform4f(const std::string& name,const glm::vec4 &value);

private:
    unsigned int m_ID;
    /**
     * @brief Compiles a specific shader from its raw source code.
     *
     * @param type The OpenGL shader type.
     * @param sourceCode The raw string containing the shader code.
     * @throws runtime_error if shader failed to compile.
     * @return The OpenGL ID of the compiled shader.
     */
    unsigned int CompileShader(unsigned int type, const std::string &sourceCode);

    /**
     * @brief Links compiled vertex and fragment shaders into a program.
     *
     * @param vertexCode The raw vertex shader source string.
     * @param fragmentCode The raw fragment shader source string.
     * @throws runtime_error if shader failed to link.
     * @return The OpenGL ID of the linked shader program.
     */
    unsigned int CreateShaderProgram(const std::string &vertexCode, const std::string &fragmentCode);

    /**
     * @brief Reads a text file from disk into a string.
     *
     * @param filePath The path to the target file.
     * @throws runtime_error if failed to open file.
     * @return A string containing the entire file's contents.
     */
    std::string ReadFile(const std::string &filePath);

    /**
     * @brief Finds the location of a uniform variable using a map.
     * 
     * @param name The key.
     * @returns The location of the uniform.
     */
    int GetUniformLoc(const std::string &name);

    std::unordered_map<std::string,int> m_UniformLocMap;
};
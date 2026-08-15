#pragma once
#include <string>

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
     *
     * @throws runtime_error if the shader source cannot be
     *         loaded, compiled, or linked successfully.
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

private:
    unsigned int m_ID;
    /**
     * @brief Compiles a specific shader from its raw source code.
     *
     * @param type The OpenGL shader type.
     * @param sourceCode The raw string containing the shader code.
     * @return The OpenGL ID of the compiled shader.
     */
    unsigned int CompileShader(unsigned int type, const std::string &sourceCode);
    /**
     * @brief Links compiled vertex and fragment shaders into a program.
     *
     * @param vertexCode The raw vertex shader source string.
     * @param fragmentCode The raw fragment shader source string.
     * @return The OpenGL ID of the linked shader program.
     */
    unsigned int CreateShaderProgram(const std::string &vertexCode, const std::string &fragmentCode);
    /**
     * @brief Reads a text file from disk into a string.
     *
     * @param filePath The path to the target file.
     * @return A string containing the entire file's contents.
     */
    std::string ReadFile(const std::string &filePath);
};
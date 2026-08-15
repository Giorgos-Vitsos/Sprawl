#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

/**
 * @brief Manages an OpenGL Vertex Array Object (VAO).
 *
 * Ties the VBO with the data layout.
 */
class VertexArray
{
public:
    /**
     * @brief Creates a new Vertex Array Object.
     */
    VertexArray();
    /**
     * @brief Destroys the VAO.
     */
    ~VertexArray();
    /**
     * @brief Binds the VAO to the active OpenGL context.
     */
    void Bind() const;
    /**
     * @brief Unbinds the active VAO.
     */
    void Unbind() const;
    /**
     * @brief Wires a Vertex Buffer to this Vertex Array using a specific layout.
     *
     * Binds the VAO and VBO, then automatically configures the OpenGL
     * vertex attribute pointers based on the provided layout specifications.
     *
     * @param vbo The Vertex Buffer Object containing the raw data.
     * @param layout The layout map describing the VBO's memory structure.
     */
    void AddBuffer(const VertexBuffer &vbo, const VertexBufferLayout &layout);

private:
    unsigned int m_ID;
};
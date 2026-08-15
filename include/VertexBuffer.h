#pragma once

/**
 * @brief Manages an OpenGL Vertex Buffer Object.
 *
 * A memory buffer stored directly on the GPU, used to hold raw vertex
 * data such as positions, normals, and texture coordinates.
 */
class VertexBuffer
{
public:
    /**
     * @brief Creates a vertex buffer and uploads data to the GPU.
     *
     * @param data Pointer to the raw vertex data.
     * @param size The total size of the data in bytes.
     */
    VertexBuffer(const void *data, unsigned int size);
    /**
     * @brief Destroys the vertex buffer.
     */
    ~VertexBuffer();
    /**
     * @brief Binds the vertex buffer to the active OpenGL context.
     */
    void Bind() const;
    /**
     * @brief Unbinds the active vertex buffer.
     */
    void Unbind() const;

private:
    unsigned int m_ID;
};
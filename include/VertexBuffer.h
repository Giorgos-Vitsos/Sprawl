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

    VertexBuffer(unsigned int maxSize);

    /**
     * @brief Destroys the vertex buffer.
     */
    ~VertexBuffer();

    /**
     * @brief Copying is disabled because the OpenGL resource
     * has unique ownership.
     */
    VertexBuffer(const VertexBuffer&) = delete;

    /**
     * @brief Copying is disabled because the OpenGL resource
     * has unique ownership.
     */
    VertexBuffer& operator=(const VertexBuffer&) = delete;

    /**
     * @brief Transfers ownership of the OpenGL vertex buffer.
     *
     * The source object is left with no owned OpenGL resource.
     */
    VertexBuffer(VertexBuffer&& other) noexcept;

    /**
     * @brief Transfers ownership of the OpenGL vertex buffer.
     */
    VertexBuffer& operator=(VertexBuffer&& other) noexcept;

    /**
     * @brief Binds the vertex buffer to the active OpenGL context.
     */
    void Bind() const;
    
    /**
     * @brief Unbinds the active vertex buffer.
     */
    void Unbind() const;

    unsigned int GetCount() const { return m_Count; }

    bool SetData(const void *data,unsigned int size);

private:
    unsigned int m_ID;
    unsigned int m_Count;
};
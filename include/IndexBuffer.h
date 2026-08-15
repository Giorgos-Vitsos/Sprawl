#pragma once

/**
 * @brief Manages an OpenGL Element Array Buffer.
 *
 * Stores index data used to connect vertices into primitives
 */
class IndexBuffer
{
public:
    /**
     * @brief Creates an index buffer and uploads data to the GPU.
     *
     * @param data Pointer to the array of indices.
     * @param count The total number of indices in the array.
     */
    IndexBuffer(const unsigned int *data, unsigned int count);

    /**
     * @brief Destroys the index buffer and frees the associated GPU memory.
     */
    ~IndexBuffer();

    /**
     * @brief Binds the index buffer to the active OpenGL context.
     */
    void Bind() const;

    /**
     * @brief Unbinds the active index buffer.
     */
    void Unbind() const;

    /**
     * @brief Retrieves the number of indices in the buffer.
     *
     * @return The total count of indices.
     */
    unsigned int GetCount() const { return m_Count; }

private:
    unsigned int m_ID;
    unsigned int m_Count;
};
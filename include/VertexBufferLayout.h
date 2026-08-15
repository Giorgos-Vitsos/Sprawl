#pragma once
#include <vector>
#include <glad/glad.h>

/**
 * @brief Describes a single attribute within a vertex.
 */
struct VertexBufferAttribute
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
};

/**
 * @brief Constructs a memory map for vertex data.
 *
 * Used to calculate the offset and stride of complex vertices so the
 * GPU knows how to interpret the raw floats in a Vertex Buffer.
 */
class VertexBufferLayout
{
public:
    /**
     * @brief Initializes an empty layout with a starting stride of 0.
     */
    VertexBufferLayout() : m_Stride(0) {}
    /**
     * @brief Pushes a new attribute into the layout.
     *
     * Triggers a static assertion failure if an unsupported type is provided.
     *
     * @tparam T The C++ data type of the attribute.
     * @param count The number of elements of this type in the attribute.
     */
    template <typename T>
    void Push(unsigned int count)
    {
        static_assert(sizeof(T) == 0, "Unsupported type");
    }
    /**
     * @brief Retrieves the list of defined vertex attributes.
     *
     * @return A constant reference to the vector of VertexBufferElements.
     */
    const std::vector<VertexBufferAttribute> &GetAttributes() const { return m_Attributes; }
    /**
     * @brief Retrieves the total size of a single vertex in bytes.
     *
     * @return The calculated stride.
     */
    unsigned int GetStride() const { return m_Stride; }

private:
    unsigned int m_Stride;
    std::vector<VertexBufferAttribute> m_Attributes;
};

template <>
inline void VertexBufferLayout::Push<float>(unsigned int count)
{
    m_Attributes.push_back({GL_FLOAT, count, GL_FALSE});
    m_Stride += count * 4;
}

template <>
inline void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Attributes.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_Stride += count * 4;
}

template <>
inline void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Attributes.push_back({GL_UNSIGNED_BYTE, count, GL_FALSE});
    m_Stride += count * 1;
}
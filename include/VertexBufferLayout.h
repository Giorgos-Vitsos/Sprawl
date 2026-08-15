#pragma once
#include <vector>
#include <glad/glad.h>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
};

class VertexBufferLayout
{
public:
    VertexBufferLayout() : m_Stride(0) {}
    template <typename T>
    void Push(unsigned int count)
    {
        static_assert(sizeof(T) == 0, "Unsupported type");
    }
    const std::vector<VertexBufferElement> &GetElements() const { return m_Elements; }
    unsigned int GetStride() const { return m_Stride; }

private:
    unsigned int m_Stride;
    std::vector<VertexBufferElement> m_Elements;
};

template <>
inline void VertexBufferLayout::Push<float>(unsigned int count)
{
    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_Stride += count * 4;
}

template <>
inline void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_Stride += count * 4;
}

template <>
inline void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_FALSE});
    m_Stride += count * 1;
}
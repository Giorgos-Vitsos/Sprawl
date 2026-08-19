#include "Mesh.h"

Mesh::Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, const VertexBufferLayout &layout) : m_VBO(vertices.data(), vertices.size() * sizeof(float)), m_IBO(indices.data(), indices.size())
{
    m_VAO.AddBuffer(m_VBO, layout);
    m_IBO.Bind();
    Unbind();
}

void Mesh::Bind() const
{
    m_VAO.Bind();
}

void Mesh::Unbind() const
{
    m_VAO.Unbind();
}

unsigned int Mesh::GetIndexCount() const
{
    return m_IBO.GetCount();
}
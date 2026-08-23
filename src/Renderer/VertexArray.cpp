#include "VertexArray.h"
#include <glad/glad.h>

VertexArray::VertexArray(){
    glGenVertexArrays(1,&m_ID);
}

VertexArray::~VertexArray(){
    glDeleteVertexArrays(1,&m_ID);
}

VertexArray::VertexArray(VertexArray&& other) noexcept : m_ID(other.m_ID) 
{
    other.m_ID = 0;
}

VertexArray& VertexArray::operator=(VertexArray&& other) noexcept {
    if (this != &other) { 
        glDeleteVertexArrays(1, &m_ID); 
        m_ID = other.m_ID;         
        other.m_ID = 0;           
    }
    return *this;
}

void VertexArray::Bind() const{
    glBindVertexArray(m_ID);
}

void VertexArray::Unbind() const{
    glBindVertexArray(0);
}

unsigned int VertexArray::GetSizeOfType(GLenum type){
    switch (type)
        {
        case GL_FLOAT :
            return 4;
        case GL_UNSIGNED_INT:
            return 4;
        case GL_UNSIGNED_BYTE:
            return 1;
        default:
            return 0;
        }
}

void VertexArray::AddBuffer(const VertexBuffer &vbo,const VertexBufferLayout &layout){
    Bind();
    vbo.Bind();
    const auto &attributes=layout.GetAttributes();
    unsigned int offset=0;

    for(unsigned int i=0;i<attributes.size();i++){//for each attribute in VBO
        const auto &attribute=attributes[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, attribute.count, attribute.type,attribute.normalized, layout.GetStride(), (const void*)(size_t)offset);  
        offset += attribute.count * GetSizeOfType(attribute.type);
    }
}
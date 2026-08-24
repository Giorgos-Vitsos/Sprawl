#include "VertexBuffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(const void*data, unsigned int size):m_Count(size/sizeof(float)/3){
    glGenBuffers(1,&m_ID);
    Bind();
    glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1,&m_ID);
}

VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept : m_ID(other.m_ID) 
{
    other.m_ID = 0;
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept {
    if (this != &other) { 
        glDeleteBuffers(1, &m_ID); 
        m_ID = other.m_ID;         
        other.m_ID = 0;           
    }
    return *this;
}

void VertexBuffer::Bind() const{
    glBindBuffer(GL_ARRAY_BUFFER,m_ID);
}

void VertexBuffer::Unbind() const{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
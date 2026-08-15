#include "IndexBuffer.h"
#include <glad/glad.h>

IndexBuffer::IndexBuffer(const unsigned int* data,unsigned int count): m_Count(count){
    glGenBuffers(1,&m_ID);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(unsigned int),data,GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer(){
    glDeleteBuffers(1,&m_ID);
}

IndexBuffer::IndexBuffer(IndexBuffer&& other) noexcept : m_ID(other.m_ID) 
{
    other.m_ID = 0;
}

IndexBuffer& IndexBuffer::operator=(IndexBuffer&& other) noexcept {
    if (this != &other) { 
        glDeleteBuffers(1, &m_ID); 
        m_ID = other.m_ID;         
        other.m_ID = 0;           
    }
    return *this;
}

void IndexBuffer::Bind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_ID);
}

void IndexBuffer::Unbind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
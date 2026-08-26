#include "VertexBuffer.h"
#include <glad/glad.h>
#include <stdexcept>

VertexBuffer::VertexBuffer(const void*data, unsigned int size):m_Count(size){
    glGenBuffers(1,&m_ID);
    Bind();
    glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);
}

VertexBuffer::VertexBuffer(unsigned int maxSize):m_Count(maxSize){
    glGenBuffers(1,&m_ID);
    Bind();
    glBufferData(GL_ARRAY_BUFFER,maxSize,nullptr,GL_DYNAMIC_DRAW);
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
        m_Count=other.m_Count;
        other.m_Count=0;           
    }
    return *this;
}

void VertexBuffer::Bind() const{
    glBindBuffer(GL_ARRAY_BUFFER,m_ID);
}

void VertexBuffer::Unbind() const{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

bool VertexBuffer::SetData(const void *data,unsigned int size){
    bool flag;
    Bind();
    if(size>m_Count){
        if(size>m_Count*2){
            *this=VertexBuffer(size);
            flag=true;
        }else{
            *this=VertexBuffer(m_Count*2);
            flag=false;
        }
    }
    glBufferSubData(GL_ARRAY_BUFFER,0,size,data);
    return flag;
};

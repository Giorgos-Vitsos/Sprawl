#include "VertexArray.h"
#include <glad/glad.h>

VertexArray::VertexArray(){
    glGenVertexArrays(1,&m_ID);
}

VertexArray::~VertexArray(){
    glDeleteVertexArrays(1,&m_ID);
}

void VertexArray::Bind() const{
    glBindVertexArray(m_ID);
}

void VertexArray::Unbind() const{
    glBindVertexArray(0);
}

void VertexArray::AddBuffer(const VertexBuffer &vbo,const VertexBufferLayout &layout){
    Bind();
    vbo.Bind();
    const auto &elements=layout.GetElements();
    unsigned int offset=0;

    for(unsigned int i=0;i<elements.size();i++){
        const auto &element=elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type,element.normalized, layout.GetStride(), (const void*)(size_t)offset);
        
        unsigned int sizeOfType;
        switch (element.type)
        {
        case GL_FLOAT:
            sizeOfType=4;
            break;
        case GL_UNSIGNED_INT:
            sizeOfType=4;
            break;
        default:
            sizeOfType=0;
            break;
        }
        offset += element.count * sizeOfType;
    }
}
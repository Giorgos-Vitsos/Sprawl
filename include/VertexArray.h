#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray{
    public:
        VertexArray();
        ~VertexArray();
        void Bind() const;
        void Unbind() const;
        void AddBuffer(const VertexBuffer &vbo,const VertexBufferLayout &layout);
    private:
        unsigned int m_ID;
};
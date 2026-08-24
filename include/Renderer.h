#pragma once
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "PerspectiveCamera.h"



struct RendererStats{
    int fps;
    int triangles;
    int vertices;
    int calls;
};

class Renderer{
    public:
        Renderer();
        void Clear();
        void Draw(Mesh &mesh,Shader &shader,Transform &trs,PerspectiveCamera &camera);
        const RendererStats GetStats() { return m_Stats;}

    private:
        RendererStats m_Stats;
};
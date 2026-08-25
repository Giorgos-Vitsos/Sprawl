#pragma once
#include <glm/glm.hpp>
#include "PerspectiveCamera.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

struct DebugVertex{
    glm::vec3 Pos;
    glm::vec3 Color;
};


class DebugRenderer{
    public:
        DebugRenderer()=delete;
        static void Init();
        static void Destroy();
        static void DrawLine(const glm::vec3& start,const glm::vec3& end,const glm::vec3& color);
        static void DrawGrid(const glm::vec3& center,const float size,const int spacing,const glm::vec3& color);
        static void DrawWireCube(const glm::vec3& center,const float size,const glm::vec3& color);
        static void Render(PerspectiveCamera &camera);
    private:
        static Shader *s_Shader;
        static VertexArray *s_VAO;
        static VertexBuffer *s_VBO;
        static std::vector<DebugVertex> s_Vertices;
};
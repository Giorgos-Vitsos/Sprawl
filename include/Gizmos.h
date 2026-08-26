#pragma once
#include <glm/glm.hpp>
#include "PerspectiveCamera.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

struct DebugVertex{
    glm::vec3 Pos;
    glm::vec3 Color;
};


class Gizmos{
    public:
        Gizmos()=delete;
        static void Init();
        static void Destroy();
        static void DrawLine(const glm::vec3& start,const glm::vec3& end,const glm::vec3& color={0.2f,0.8f,0.6f});
        static void DrawGrid(const glm::vec3& center={0,0,0},const float size=100,const int spacing=1,const glm::vec3& color={0.87f,0.87f,0.87f});
        static void DrawWireCube(const glm::vec3& center={0,0,0},const float size=1,const glm::vec3& color={0.2f,0.8f,0.6f});
        static void Render(PerspectiveCamera &camera);
    private:
        static Shader *s_Shader;
        static VertexArray *s_VAO;
        static VertexBuffer *s_VBO;
        static VertexBufferLayout *s_Layout;
        static std::vector<DebugVertex> s_Vertices;
};
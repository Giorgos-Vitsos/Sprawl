#include "DebugRenderer.h"
#include "VertexBufferLayout.h"

Shader* DebugRenderer::s_Shader=nullptr;
VertexArray* DebugRenderer::s_VAO=nullptr;
VertexBuffer* DebugRenderer::s_VBO=nullptr;
std::vector<DebugVertex> DebugRenderer::s_Vertices;

void DebugRenderer::Init(){
    s_Shader=new Shader("assets/shaders/Debug.vert", "assets/shaders/Debug.frag");
    s_VAO=new VertexArray();
    VertexBufferLayout layout;
    layout.Push<float>(6);
    s_VBO=new VertexBuffer(1000);
    s_Vertices.reserve(1000);
}

void DebugRenderer::Render(PerspectiveCamera &camera){
    if(s_Vertices.size()==0) return;
    unsigned int totalSize=s_Vertices.size()*sizeof(DebugVertex);
    s_VBO->SetData(s_Vertices.data(),totalSize);
    s_VAO->Bind();
    s_Shader->Bind();
    s_Shader->SetUniformMat4f("u_MVP",camera.GetViewProjMatrix());
    glDrawArrays(GL_LINES,0,s_Vertices.size());
}

void DebugRenderer::DrawLine(const glm::vec3& start,const glm::vec3& end,const glm::vec3& color){};
void DebugRenderer::DrawGrid(const glm::vec3& center,const float size,const int spacing,const glm::vec3& color){};
void DebugRenderer::DrawWireCube(const glm::vec3& center,const float size,const glm::vec3& color){};
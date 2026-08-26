#include "Gizmos.h"
#include "VertexBufferLayout.h"

Shader* Gizmos::s_Shader=nullptr;
VertexArray* Gizmos::s_VAO=nullptr;
VertexBuffer* Gizmos::s_VBO=nullptr;
std::vector<DebugVertex> Gizmos::s_Vertices;

void Gizmos::Init(){
    s_Shader=new Shader("assets/shaders/Debug.vert", "assets/shaders/Debug.frag");
    s_VAO=new VertexArray();
    VertexBufferLayout layout;
    layout.Push<float>(6);
    s_VBO=new VertexBuffer(1000);
    s_Vertices.reserve(1000);
}

void Gizmos::Destroy(){
    delete &s_Shader;
    delete &s_VAO;
    delete &s_VBO;
    delete &s_Vertices;
}

void Gizmos::Render(PerspectiveCamera &camera){
    if(s_Vertices.size()==0) return;
    unsigned int totalSize=s_Vertices.size()*sizeof(DebugVertex);
    s_VBO->SetData(s_Vertices.data(),totalSize);
    s_VAO->Bind();
    s_Shader->Bind();
    s_Shader->SetUniformMat4f("u_MVP",camera.GetViewProjMatrix());
    glDrawArrays(GL_LINES,0,s_Vertices.size());
    s_Vertices.clear();
}

void Gizmos::DrawLine(const glm::vec3& start,const glm::vec3& end,const glm::vec3& color){

};

void Gizmos::DrawGrid(const glm::vec3& center,const float size,const int spacing,const glm::vec3& color){};
void Gizmos::DrawWireCube(const glm::vec3& center,const float size,const glm::vec3& color){};
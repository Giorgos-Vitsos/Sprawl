#include "Gizmos.h"


Shader* Gizmos::s_Shader=nullptr;
VertexArray* Gizmos::s_VAO=nullptr;
VertexBuffer* Gizmos::s_VBO=nullptr;
VertexBufferLayout* Gizmos::s_Layout=nullptr;
std::vector<DebugVertex> Gizmos::s_Vertices;

void Gizmos::Init(){
    s_Shader=new Shader("assets/shaders/Gizmos.vert", "assets/shaders/Gizmos.frag");
    s_VAO=new VertexArray();
    s_Layout=new VertexBufferLayout();
    s_Layout->Push<float>(3);
    s_Layout->Push<float>(3);
    s_VBO=new VertexBuffer(1000);
    s_VAO->AddBuffer(*s_VBO,*s_Layout);
    s_Vertices.reserve(1000);
}

void Gizmos::Destroy(){
    delete s_Shader;
    delete s_VAO;
    delete s_VBO;
}

void Gizmos::Render(PerspectiveCamera &camera){
    if(s_Vertices.size()==0) return;
    unsigned int totalSize=s_Vertices.size()*sizeof(DebugVertex);
    if(s_VBO->SetData(s_Vertices.data(),totalSize)){
        s_VAO->AddBuffer(*s_VBO,*s_Layout);
    }
    s_VAO->Bind();
    s_Shader->Bind();
    s_Shader->SetUniformMat4f("u_MVP",camera.GetViewProjMatrix());
    glDrawArrays(GL_LINES,0,s_Vertices.size());
    s_Vertices.clear();
}

void Gizmos::DrawLine(const glm::vec3& start,const glm::vec3& end,const glm::vec3& color){
    DebugVertex startPoint,endPoint;
    startPoint.Pos=start;
    startPoint.Color=color;
    endPoint.Pos=end;
    endPoint.Color=color;
    s_Vertices.push_back(startPoint);
    s_Vertices.push_back(endPoint);
};

void Gizmos::DrawWireCube(const glm::vec3& center,const float size,const glm::vec3& color){
    float offset=size/2;

    glm::vec3 topFL=center+glm::vec3(-offset,offset,-offset);
    glm::vec3 topBL=center+glm::vec3(-offset,offset,offset);
    glm::vec3 topFR=center+glm::vec3(offset,offset,-offset);
    glm::vec3 topBR=center+glm::vec3(offset,offset,offset);
    glm::vec3 bottomFL=center+glm::vec3(-offset,-offset,-offset);
    glm::vec3 bottomBL=center+glm::vec3(-offset,-offset,offset);
    glm::vec3 bottomFR=center+glm::vec3(offset,-offset,-offset);
    glm::vec3 bottomBR=center+glm::vec3(offset,-offset,offset);

    //top square
    DrawLine(topFL,topFR,color);
    DrawLine(topBL,topBR,color);
    DrawLine(topFL,topBL,color);
    DrawLine(topFR,topBR,color);

    //bottom square
    DrawLine(bottomFL,bottomFR,color);
    DrawLine(bottomBL,bottomBR,color);
    DrawLine(bottomFL,bottomBL,color);
    DrawLine(bottomFR,bottomBR,color);

    //sides
    DrawLine(topFL,bottomFL,color);
    DrawLine(topBL,bottomBL,color);
    DrawLine(topFR,bottomFR,color);
    DrawLine(topBR,bottomBR,color);

};

void Gizmos::DrawGrid(const glm::vec3& center,const float size,const int spacing,const glm::vec3& color){
    for(float i=-size/2;i<=size/2;i+=spacing){
        //x
        glm::vec3 startPos=center+glm::vec3(i,0,-size/2);
        glm::vec3 endPos=center+glm::vec3(i,0,size/2);
        DrawLine(startPos,endPos,color);

        //z
        startPos=center+glm::vec3(-size/2,0,i);
        endPos=center+glm::vec3(size/2,0,i);
        DrawLine(startPos,endPos,color);
    }
};


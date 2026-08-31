#include "Renderer.h"
#include <iostream>
#include <TimeHelper.h>
#include <GLFW/glfw3.h>

Renderer::Renderer(){
    if(glfwGetCurrentContext()== nullptr){
        throw std::runtime_error("Renderer cant initialize because glfw context dont exist.");
    }
    glEnable(GL_DEPTH_TEST);
    ChangeBackFaceCullingState(true);
}

void Renderer::Clear(){
    m_Stats.fps=0;//the stats are about each frame so we reset them per frame
    m_Stats.triangles=0;
    m_Stats.vertices=0;
    m_Stats.calls=0;
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
};

void Renderer::Draw(Mesh &mesh,Shader &shader,Transform &trs,PerspectiveCamera &camera){
    glm::mat4 mvp=camera.GetViewProjMatrix()*trs.GetModelMatrix();
    shader.SetUniformMat4f("u_MVP",mvp);
    mesh.Draw();
    m_Stats.fps=1/TimeHelper::GetDeltaTime();//frames is based on time passed
    m_Stats.triangles+=mesh.GetIndexCount()/3;//3 indices make 1 triangle
    m_Stats.vertices+=mesh.GetVerticesCount();
    m_Stats.calls++;
};

void Renderer::ChangeBackFaceCullingState(bool state){
    if(state){
        glEnable(GL_CULL_FACE);
    }else{
        glDisable(GL_CULL_FACE);
    }
};
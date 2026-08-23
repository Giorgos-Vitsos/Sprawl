#include "Renderer.h"

void Renderer::Clear(){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
};

void Renderer::Draw(Mesh &mesh,Shader &shader,Transform &trs,PerspectiveCamera &camera){
    glm::mat4 mvp=camera.GetViewProjMatrix()*trs.GetModelMatrix();
    shader.SetUniformMat4f("u_MVP",mvp);
    mesh.Draw();
};
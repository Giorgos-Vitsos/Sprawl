#include "Window.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "OrthographicCamera.h"
#include "PrimitiveCreator.h"
#include "Transform.h"
#include "PerspectiveCamera.h"

int main() {
    try {
        Window window(800, 600, "Sprawl Engine");

        Mesh triangle=PrimitiveCreator::CreateTriangle();
        Transform triangleTRS;
        
        Mesh cube=PrimitiveCreator::CreateCube();
        Transform cubeTRS;

        Shader shader("assets/shaders/Basic.vert", "assets/shaders/Basic.frag");

        PerspectiveCamera camera(45.0f,800.0f/600.0f,0.1f,100.0f);
        camera.SetPos(glm::vec3(0,0,3));
        
        float angle=0.0f;
        float pos=0.0f;
        glEnable(GL_DEPTH_TEST);
        std::cout << "Triangle Indices: " << triangle.GetIndexCount() << std::endl;
        while (!window.ShouldClose()) {
            window.ProcessInput();
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            angle+=0.001f;
            pos+=0.0001f;

            //first object
            cubeTRS.SetRot(glm::vec3(angle,angle,0));
            cubeTRS.SetPos(glm::vec3(pos,pos,0));
            glm::mat4 mvp1=camera.GetViewProjMatrix()*cubeTRS.GetModelMatrix();
            shader.SetUniformMat4f("u_MVP",mvp1);
            cube.Bind();
            glDrawElements(GL_TRIANGLES, cube.GetIndexCount(), GL_UNSIGNED_INT, nullptr);
            //second object
            triangleTRS.SetPos(glm::vec3(1.2f,-0.5,0));
            triangleTRS.SetRot(glm::vec3{angle,0,angle});
            glm::mat4 mvp2=camera.GetViewProjMatrix()*triangleTRS.GetModelMatrix();
            shader.SetUniformMat4f("u_MVP",mvp2);
            triangle.Bind();
            glDrawElements(GL_TRIANGLES, triangle.GetIndexCount(), GL_UNSIGNED_INT, nullptr);

            window.SwapBuffersAndPoll();
        }
    } 

    catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}
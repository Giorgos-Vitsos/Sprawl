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
#include "PrimitiveCreator.h"
#include "Transform.h"
#include "CamController.h"
#include "TimeHelper.h"

int main() {
    try {
        Window window(800, 600, "Sprawl Engine");

        Mesh triangle=PrimitiveCreator::CreateTriangle();
        Transform triangleTRS;
        
        Mesh cube=PrimitiveCreator::CreateCube();
        Transform cubeTRS;

        Shader shader("assets/shaders/Basic.vert", "assets/shaders/Basic.frag");

        PerspectiveCamera camera(45.0f,800.0f/600.0f,0.1f,100.0f);
        CamController controller(camera);

        glEnable(GL_DEPTH_TEST);
        while (!window.ShouldClose()) {
            TimeHelper::Tick();
            
            window.ProcessInput();
            controller.Update();
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            //first object
            glm::mat4 mvp1=camera.GetViewProjMatrix()*cubeTRS.GetModelMatrix();
            shader.SetUniformMat4f("u_MVP",mvp1);
            cube.Bind();
            cube.Draw();
            //second object
            triangleTRS.SetPos(glm::vec3(1.2f,0,0));
            glm::mat4 mvp2=camera.GetViewProjMatrix()*triangleTRS.GetModelMatrix();
            shader.SetUniformMat4f("u_MVP",mvp2);
            triangle.Bind();
            triangle.Draw();

            window.SwapBuffersAndPoll();
        }
    } 

    catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}
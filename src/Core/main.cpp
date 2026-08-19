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

int main() {
    try {
        Window window(800, 600, "Graphics Engine - Giorgos Vitsos");

        Mesh triangle=PrimitiveCreator::CreateTriangle();
        Mesh cube=PrimitiveCreator::CreateCube();

        Shader shader("assets/shaders/Basic.vert", "assets/shaders/Basic.frag");

        OrthographicCamera camera(-2.0f, 2.0f, -1.5f, 1.5f,-100.0f,100.0f);

        
        float angle=0.0f;
        glEnable(GL_DEPTH_TEST);
        std::cout << "Triangle Indices: " << triangle.GetIndexCount() << std::endl;
        while (!window.ShouldClose()) {
            window.ProcessInput();
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            angle+=0.001f;

            //first object
            glm::mat4 model1=glm::translate(glm::mat4(1.0f),glm::vec3(0,0,0));
            model1=glm::rotate(model1,angle,glm::vec3(1,1,0));
            glm::mat4 mvp1=camera.GetViewProjMatrix()*model1;
            shader.SetUniformMat4f("u_MVP",mvp1);
            cube.Bind();
            glDrawElements(GL_TRIANGLES, cube.GetIndexCount(), GL_UNSIGNED_INT, nullptr);
            //second object
            glm::mat4 model2=glm::translate(glm::mat4(1.0f),glm::vec3(1.2f,-0.5,0));
            model2=glm::rotate(model2,angle,glm::vec3(1,0,1));
            glm::mat4 mvp2=camera.GetViewProjMatrix()*model2;
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
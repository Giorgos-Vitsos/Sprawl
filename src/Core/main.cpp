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

int main() {
    try {
        Window window(800, 600, "Graphics Engine - Giorgos Vitsos");

        std::vector<float> vertices = {
             0.5f,  0.5f, 0.0f, //0
             0.5f, -0.5f, 0.0f, //1
            -0.5f, -0.5f, 0.0f, //2
            -0.5f,  0.5f, 0.0f  //3
        };

        std::vector<unsigned int> indices = {
            0, 1, 3, 
            1, 2, 3 
        };

        VertexBufferLayout layout;
        layout.Push<float>(3);

        Mesh mesh(vertices,indices,layout);

        Shader shader("assets/shaders/Basic.vert", "assets/shaders/Basic.frag");
        glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
        glm::mat4 model=glm::translate(glm::mat4(1.0f),glm::vec3(0.5,0,0));
        glm::mat4 view=glm::translate(glm::mat4(1.0f),glm::vec3(-0.5,0,0));

        glm::mat4 mvp=proj*view*model;


        while (!window.ShouldClose()) {
            window.ProcessInput();

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shader.SetUniformMat4f("u_MVP",mvp);
            mesh.Bind();
            
            glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, nullptr);
            window.SwapBuffersAndPoll();
        }
    } 

    catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}
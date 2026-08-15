#include "Window.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include <iostream>

int main() {
    try {
        Window window(800, 600, "Graphics Engine - Giorgos Vitsos");

        float vertices[] = {
             0.5f,  0.5f, 0.0f, //0
             0.5f, -0.5f, 0.0f, //1
            -0.5f, -0.5f, 0.0f, //2
            -0.5f,  0.5f, 0.0f  //3
        };

        unsigned int indices[] = {
            0, 1, 3, 
            1, 2, 3 
        };


        VertexBuffer vbo(vertices, sizeof(vertices));
        IndexBuffer ibo(indices,6);

        VertexBufferLayout layout;
        layout.Push<float>(3);

        VertexArray vao;
        vao.AddBuffer(vbo,layout);
        
        ibo.Bind();

        Shader shader("assets/shaders/Basic.vert", "assets/shaders/Basic.frag");

        while (!window.ShouldClose()) {
            window.ProcessInput();

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shader.Bind();
            vao.Bind();
            
            glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
            window.SwapBuffersAndPoll();
        }
    } 

    catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}
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
#include "Renderer.h"

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
        Renderer renderer;

        glEnable(GL_DEPTH_TEST);
        while (!window.ShouldClose()) {
            TimeHelper::Tick();
            renderer.Clear();

            window.ProcessInput();
            controller.Update();

            renderer.Draw(cube,shader,cubeTRS,camera);
            triangleTRS.SetPos(glm::vec3(1.2f,0,0));
            renderer.Draw(triangle,shader,triangleTRS,camera);

            window.SwapBuffersAndPoll();
        }
    } 

    catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}
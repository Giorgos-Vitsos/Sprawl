#include "Window.h"
#include "PrimitiveCreator.h"
#include "CamController.h"
#include "TimeHelper.h"
#include "Renderer.h"
#include "Gizmos.h"
#include <iostream>

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
        Gizmos::Init();

        while (!window.ShouldClose()) {

            TimeHelper::Tick();
            Gizmos::DrawGrid();
            
            renderer.Clear();
            window.ProcessInput();
            controller.Update();

            renderer.Draw(cube,shader,cubeTRS,camera);
            triangleTRS.SetPos(glm::vec3(0,0,-5));
            triangleTRS.SetScale(glm::vec3(5,5,5));
            renderer.Draw(triangle,shader,triangleTRS,camera);
            
            window.SetStats(renderer.GetStats());
            Gizmos::Render(camera);
            window.SwapBuffersAndPoll();
        }
        Gizmos::Destroy();
    }catch (const std::exception& e) {
        std::cerr << "\n\033[31mFatal Error: " << e.what() << "\033[0m\n";
        return -1;
    }

    return 0;
}
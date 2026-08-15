#include "Window.h"

int main() {

    Window window(800, 600, "Graphics Engine Test");


    while (!window.ShouldClose()) {
        
        window.ProcessInput();

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.SwapBuffersAndPoll();
    }
    
    return 0;
}
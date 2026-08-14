#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Callback function to adjust the viewport when the user resizes the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Note: glViewport requires GLAD/GLEW to be initialized first to work properly.
    // We will hook this up fully in the next step.
}

// Keep all input logic centralized
void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// FIX: Changed back to bool to make the if(!initializeLib()) check work correctly
bool initializeLib(){
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return true; // FIX: Added missing semicolon
}

// FIX: Added the window pointer as a parameter so the function can see it
void render(GLFWwindow* window){
    while (!glfwWindowShouldClose(window)) {
        // Handle input
        processInput(window);

        // [RENDERING COMMANDS WILL GO HERE]
        // Example: glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // Example: glClear(GL_COLOR_BUFFER_BIT);

        // Swap the back buffer to the front and poll for events (mouse, keyboard)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main() {
    // 1. Initialize GLFW
    if (!initializeLib()) {
        return -1; // If it failed, exit the program safely
    }

    // 2. Create the Window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Graphics Engine - Test", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // FIX: Restored the missing 'i' in 'if'
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600);

    // 3. The Render Loop
    // FIX: Passed the window into the render function
    render(window);

    // 4. Clean up resources
    glfwTerminate();
    return 0;
}
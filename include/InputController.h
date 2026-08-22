#pragma once
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class InputController{
    public:
        static void Init(GLFWwindow *window);
        InputController()=delete;
        static bool IsKeyPressed(int keycode);
        static bool IsMouseButtonPressed(int button);
        static glm::vec2 GetMouseDelta();

    private:
        static GLFWwindow *m_Window;
        static double m_LastY;
        static double m_LastX;
};
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
        static double GetScrollDeltaY();
        static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    private:
        static GLFWwindow *s_Window;
        static double s_LastY;
        static double s_LastX;
        static double s_ScrollDeltaY;
};
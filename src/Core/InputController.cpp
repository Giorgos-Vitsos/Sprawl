#include "InputController.h"

GLFWwindow *InputController::s_Window=nullptr;
double InputController::s_LastY=0;
double InputController::s_LastX=0;
double InputController::s_ScrollDeltaY=0;

void InputController::Init(GLFWwindow *window){
    s_Window=window;
    glfwGetCursorPos(s_Window,&s_LastX,&s_LastY);
    glfwSetScrollCallback(s_Window,ScrollCallback);
}

bool InputController::IsKeyPressed(int keycode){
    return glfwGetKey(s_Window, keycode) == GLFW_PRESS;
}

bool InputController::IsMouseButtonPressed(int button){
    return glfwGetMouseButton(s_Window,button)==GLFW_PRESS;
};

glm::vec2 InputController::GetMouseDelta(){
    double curX,curY,deltaX,deltaY;
    glfwGetCursorPos(s_Window,&curX,&curY);
    deltaX=curX-s_LastX;
    deltaY=curY-s_LastY;
    s_LastX=curX;
    s_LastY=curY;
    return glm::vec2{deltaX,deltaY};
};

double InputController::GetScrollDeltaY(){
    double scrollDeltaY=s_ScrollDeltaY;
    s_ScrollDeltaY=0;
    return scrollDeltaY;
};

void InputController::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset){
    s_ScrollDeltaY+=yoffset;
};
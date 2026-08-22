#include "InputController.h"

GLFWwindow *InputController::m_Window=nullptr;
double InputController::m_LastY=0;
double InputController::m_LastX=0;
double InputController::m_ScrollDeltaY=0;

void InputController::Init(GLFWwindow *window){
    m_Window=window;
    glfwGetCursorPos(m_Window,&m_LastX,&m_LastY);
    glfwSetScrollCallback(m_Window,ScrollCallback);
}

bool InputController::IsKeyPressed(int keycode){
    return glfwGetKey(m_Window, keycode) == GLFW_PRESS;
}

bool InputController::IsMouseButtonPressed(int button){
    return glfwGetMouseButton(m_Window,button)==GLFW_PRESS;
};

glm::vec2 InputController::GetMouseDelta(){
    double curX,curY,deltaX,deltaY;
    glfwGetCursorPos(m_Window,&curX,&curY);
    deltaX=curX-m_LastX;
    deltaY=curY-m_LastY;
    m_LastX=curX;
    m_LastY=curY;
    return glm::vec2{deltaX,deltaY};
};

double InputController::GetScrollDeltaY(){
    double scrollDeltaY=m_ScrollDeltaY;
    m_ScrollDeltaY=0;
    return scrollDeltaY;
};

void InputController::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset){
    m_ScrollDeltaY+=yoffset;
};
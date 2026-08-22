#include "CamController.h"
#include "InputController.h"
#include <iostream>

CamController::CamController(PerspectiveCamera &camera):m_Camera(camera),m_Sensitivity(0.005f),m_PanningSpeed(0.02f){}

void CamController::Update(float deltaTime){
    glm::vec2 delta=InputController::GetMouseDelta();
    if(InputController::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_MIDDLE)){
        if(InputController::IsKeyPressed(GLFW_KEY_LEFT_SHIFT)||InputController::IsKeyPressed(GLFW_KEY_RIGHT_SHIFT)){
            Pan(delta);
        }else{
            Move(delta);
        }
    }
    
    
}

void CamController::Move(glm::vec2 &delta){
    delta.x*=m_Sensitivity;
    delta.y*=m_Sensitivity;
    float pitch=m_Camera.GetPichYaw().x;
    float yaw=m_Camera.GetPichYaw().y;
    m_Camera.SetPitchYaw(pitch+delta.y,yaw-delta.x);
}

void CamController::Pan(glm::vec2 &delta){
    glm::vec3 forward=glm::normalize(m_Camera.GetFocalPoint()-m_Camera.GetPos());
    glm::vec3 right=glm::normalize(glm::cross(forward,WORLD_UP));
    glm::vec3 localUp=glm::normalize(glm::cross(right,forward));
    
    glm::vec3 x=delta.x*right*m_PanningSpeed;
    glm::vec3 y=delta.y*localUp*m_PanningSpeed;
    m_Camera.SetFocalPoint(glm::vec3(m_Camera.GetFocalPoint()-x+y));
}
#include "CamController.h"
#include "InputController.h"
#include "TimeHelper.h"

CamController::CamController(PerspectiveCamera &camera):m_Camera(camera),m_Sensitivity(0.5),m_PanningSpeed(1),m_ZoomSpeed(15){}

void CamController::Update(){
    glm::vec2 delta=InputController::GetMouseDelta();//we get mouse movement
    if(InputController::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_MIDDLE)){
        if(InputController::IsKeyPressed(GLFW_KEY_LEFT_SHIFT)||InputController::IsKeyPressed(GLFW_KEY_RIGHT_SHIFT)){
            Pan(delta);
        }else{
            Move(delta);
        }
    }
    Zoom();
}

void CamController::Move(glm::vec2 &delta){
    delta.x*=m_Sensitivity*TimeHelper::GetDeltaTime();
    delta.y*=m_Sensitivity*TimeHelper::GetDeltaTime();
    float pitch=m_Camera.GetPichYaw().x;
    float yaw=m_Camera.GetPichYaw().y;
    m_Camera.SetPitchYaw(pitch+delta.y,yaw-delta.x);
}

void CamController::Pan(glm::vec2 &delta){
    glm::vec3 forward=glm::normalize(m_Camera.GetFocalPoint()-m_Camera.GetPos());
    glm::vec3 right=glm::normalize(glm::cross(forward,WORLD_UP));
    glm::vec3 localUp=glm::normalize(glm::cross(right,forward));
    glm::vec3 x=delta.x*right*m_PanningSpeed *(float)TimeHelper::GetDeltaTime();
    glm::vec3 y=delta.y*localUp*m_PanningSpeed*(float)TimeHelper::GetDeltaTime();
    m_Camera.SetFocalPoint(glm::vec3(m_Camera.GetFocalPoint()-x+y));
}

void CamController::Zoom(){
    double scrollDeltaY=InputController::GetScrollDeltaY();
    float dis=m_Camera.GetDis()-scrollDeltaY*m_ZoomSpeed*TimeHelper::GetDeltaTime();
    m_Camera.SetDis(dis);
}
    
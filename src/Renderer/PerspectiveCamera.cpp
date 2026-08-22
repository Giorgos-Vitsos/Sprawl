#include "PerspectiveCamera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <algorithm>

PerspectiveCamera::PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip):m_ViewMatrix(1.0f),m_Pos(0,0,0),m_Pitch(0),m_Yaw(0),m_Distance(3.0f),m_FocalPoint(0){
    m_ProjMatrix=glm::perspective(glm::radians(fov),aspectRatio,nearClip,farClip);
    RecalcViewMatrix();
}

void PerspectiveCamera::RecalcViewMatrix(){

    float x=m_FocalPoint.x+m_Distance*cos(m_Pitch)*sin(m_Yaw);
    float y=m_FocalPoint.y+m_Distance*sin(m_Pitch);
    float z=m_FocalPoint.z+m_Distance*cos(m_Pitch)*cos(m_Yaw);

    m_Pos=glm::vec3(x,y,z);
    m_ViewMatrix=glm::lookAt(glm::vec3(m_Pos), glm::vec3(m_FocalPoint),WORLD_UP);
    m_ViewProjMatrix=m_ProjMatrix*m_ViewMatrix;
}

void PerspectiveCamera::SetFocalPoint(const glm::vec3& focalPoint){
    m_FocalPoint=focalPoint;
    RecalcViewMatrix();
};

void PerspectiveCamera::SetDis(float dis){
    m_Distance=std::clamp(dis,0.1f,INFINITY);
    RecalcViewMatrix();
};

void PerspectiveCamera::SetPitchYaw(float pitch,float yaw){
    m_Pitch=std::clamp(pitch,glm::radians(-89.9f),glm::radians(89.9f));
    m_Yaw=yaw;
    RecalcViewMatrix();
};

const glm::mat4 &PerspectiveCamera::GetViewProjMatrix() const{ return m_ViewProjMatrix;};

const glm::vec2 PerspectiveCamera::GetPichYaw() const {return glm::vec2(m_Pitch,m_Yaw);}
    
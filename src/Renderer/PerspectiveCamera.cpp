#include "PerspectiveCamera.h"
#include <glm/gtc/matrix_transform.hpp>

PerspectiveCamera::PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip):m_ViewMatrix(1.0f),m_Pos(0,0,0){
    m_ProjMatrix=glm::perspective(glm::radians(fov),aspectRatio,nearClip,farClip);
    RecalcViewMatrix();
}

void PerspectiveCamera::RecalcViewMatrix(){

    glm::mat4 transform=glm::translate(glm::mat4(1.0f),m_Pos);
    m_ViewMatrix=glm::inverse(transform);
    m_ViewProjMatrix=m_ProjMatrix*m_ViewMatrix;
}

void PerspectiveCamera::SetPos(const glm::vec3& pos){
    m_Pos=pos;
    RecalcViewMatrix();
};

const glm::mat4 &PerspectiveCamera::GetViewProjMatrix() const{ return m_ViewProjMatrix;};
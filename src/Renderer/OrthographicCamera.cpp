#include "OrthographicCamera.h"
#include <glm/gtc/matrix_transform.hpp>

OrthographicCamera::OrthographicCamera(float left,float right,float botom,float top,float nearClip,float farClip):m_ViewMatrix(1.0f),m_Pos(0,0,0),m_Rot(0){
    m_ProjMatrix=glm::ortho(left, right, botom, top, nearClip,farClip);
    RecalcViewMatrix();
}

const glm::mat4 & OrthographicCamera::GetViewMatrix() const {return m_ViewMatrix;};
const glm::mat4 &OrthographicCamera::GetProjMatrix() const{ return m_ProjMatrix;};
const glm::mat4 &OrthographicCamera::GetViewProjMatrix() const{ return m_ViewProjMatrix;};

void OrthographicCamera::SetPos(const glm::vec3& pos){ 
    m_Pos=pos;
    RecalcViewMatrix();
};
void OrthographicCamera::SetRot(float rot){
    m_Rot=rot;
    RecalcViewMatrix();
};

void OrthographicCamera::RecalcViewMatrix(){
    glm::mat4 transform=glm::translate(glm::mat4(1.0f),m_Pos);
    transform=glm::rotate(transform,m_Rot,glm::vec3(0,0,1));
    m_ViewMatrix=glm::inverse(transform);
    m_ViewProjMatrix=m_ProjMatrix*m_ViewMatrix;
};
#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

Transform::Transform():m_Pos(0),m_Rot(0),m_Scale(1.0f),m_ModelMatrix(glm::mat4(1.0f)){};

void Transform::SetPos(const glm::vec3& pos){
    m_Pos=pos;
    RecalcModelMatrix();
};

void Transform::SetRot( const glm::vec3& rot){
    m_Rot=rot;
     RecalcModelMatrix();
 };
void Transform::SetScale( const glm::vec3& scale){
    m_Scale=scale;
    RecalcModelMatrix();
};

const glm::vec3& Transform::GetPos()  const{return m_Pos;};

const glm::vec3& Transform::GetRot()  const{return m_Rot;};

const glm::vec3& Transform::GetScale()  const{return m_Scale;};

void Transform::RecalcModelMatrix(){
    glm::mat4 scaleMatrix=glm::scale(glm::mat4(1.0f),m_Scale);
    glm::mat4 rotMatrix=glm::mat4_cast(glm::quat(m_Rot));
    glm::mat4 tranMatrix=glm::translate(glm::mat4(1.0f),m_Pos);
    
    m_ModelMatrix= tranMatrix*rotMatrix*scaleMatrix;
};

const glm::mat4& Transform::GetModelMatrix() const{return m_ModelMatrix;};
#pragma once
#include <glm/glm.hpp>

class OrthographicCamera{
    public:
        OrthographicCamera(float left,float right,float botom,float top,float nearClip=-1.0f,float farClip=1.0f);
        const glm::mat4 &GetViewProjMatrix() const;
        void SetPos(const glm::vec3& pos);
        void SetRot(float rot);
    private:
        void RecalcViewMatrix();
        glm::mat4 m_ProjMatrix;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ViewProjMatrix;
        glm::vec3 m_Pos;
        float m_Rot;
};
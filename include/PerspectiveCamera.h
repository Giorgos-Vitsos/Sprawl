#pragma once
#include <glm/glm.hpp>

class PerspectiveCamera{
    public:
        PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip);
        const glm::mat4 &GetViewProjMatrix() const;
        void SetPos(const glm::vec3& pos);
    private:
        void RecalcViewMatrix();
        glm::mat4 m_ProjMatrix;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ViewProjMatrix;
        glm::vec3 m_Pos;
};
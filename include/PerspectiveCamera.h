#pragma once
#include <glm/glm.hpp>

class PerspectiveCamera{
    public:
        PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip);
        const glm::mat4 &GetViewProjMatrix() const;
        void SetDis(float dis);
        void SetFocalPoint(const glm::vec3 &focalPoint);
        void SetPitchYaw(float pitch,float yaw);
    private:
        void RecalcViewMatrix();
        glm::mat4 m_ProjMatrix;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ViewProjMatrix;
        glm::vec3 m_Pos;
        glm::vec3 m_FocalPoint;
        float m_Distance;
        float m_Pitch;
        float m_Yaw;
};
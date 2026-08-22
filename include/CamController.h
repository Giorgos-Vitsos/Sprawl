#pragma once
#include "PerspectiveCamera.h"
class CamController{
    public:
        CamController(PerspectiveCamera &camera);
        void Update(float deltaTime);
    private:
        float m_Sensitivity;
        float m_PanningSpeed;
        PerspectiveCamera &m_Camera;
        void Move(glm::vec2 &delta);
        void Pan(glm::vec2 &delta);
        void Zoom(glm::vec2 &delta);
};
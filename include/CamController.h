#pragma once
#include "PerspectiveCamera.h"
class CamController{
    public:
        CamController(PerspectiveCamera &camera);
        void Update();
    private:
        float m_Sensitivity;
        float m_PanningSpeed;
        float m_ZoomSpeed;
        PerspectiveCamera &m_Camera;
        void Move(glm::vec2 &delta);
        void Pan(glm::vec2 &delta);
        void Zoom();
};
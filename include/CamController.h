#pragma once
#include "PerspectiveCamera.h"

/**
 * @brief Manages the application's perspective cameras movement.
 *
 * Responsible for reading mouse inputs and translating 
 * them into camera movement (move,pan and zoom).
 */
class CamController
{
public:
    /**
     * @brief CamController constructor.
     * @param camera The camera which it controlls.
     */
    CamController(PerspectiveCamera &camera);

    /**
     * @brief Reads the users mouse input and translates them to camera movement.
     */
    void Update();
private:
    /**
     * @brief Handles camera basic rotation around focal point.
     * @param delta The mouse cordinates.
     */
    void Move(glm::vec2 &delta);

    /**
     * @brief Changes cameras focal point.
     * @param delta The mouse cordinates.
     */
    void Pan(glm::vec2 &delta);

    /**
     * @brief Changes cameras distance from focal point.
     */
    void Zoom();

    float m_Sensitivity;
    float m_PanningSpeed;
    float m_ZoomSpeed;
    PerspectiveCamera &m_Camera;
};
#pragma once
#include <glm/glm.hpp>

/**
 * @brief Engine's testing camera.
 * 
 * Responsible for initializing an orthographic 
 * camera and calculating the view and projection matrix.
 */
class OrthographicCamera{
    public:
        /**
         * @brief Initializes an orthographic camera.
         * 
         * @param left The left corner of where the camera looks.
         * @param right The right corner of where the camera looks.
         * @param bottom The bottom of where the camera looks.
         * @param top The top of where the camera looks.
         * @param nearClip The min distance in which the camera sees objects.
         * @param farClip The max distance in which the camera sees objects.
         */
        OrthographicCamera(float left,float right,float bottom,float top,float nearClip=-1.0f,float farClip=1.0f);

        /**
         * @brief Returns the ViewProjection matrix.
         * 
         * @returns The ViewProjection of the camera.
         */
        const glm::mat4 &GetViewProjMatrix() const;

        /**
         * @brief Sets the position of the camera.
         * 
         * @param pos The position of the camera.
         */
        void SetPos(const glm::vec3& pos);

        /**
         * @brief Sets the rotation of the camera.
         * 
         * @param rot The rotation of the camera.
         */
        void SetRot(float rot);
    private:
        /**
         * @brief Calculates the new view matrix and updates
         * the ViewProjection matrix
         */
        void RecalcViewMatrix();
        glm::mat4 m_ProjMatrix;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ViewProjMatrix;
        glm::vec3 m_Pos;
        float m_Rot;
};
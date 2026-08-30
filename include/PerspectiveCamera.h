#pragma once
#include <glm/glm.hpp>
/**
 * @brief Defines the world's up axis.
 */
#define WORLD_UP glm::vec3(0,1,0)

/**
 * @brief The engine's main camera.
 * 
 * Responsible for initializing a persepctive camera, setting its 
 * position in the world and calculating the ViewProjection matrix.
 */
class PerspectiveCamera{
    public:
        /**
         * @brief Initializes a perspective camera.
         * 
         * @param fov The field of view of the camera in degrees.
         * @param aspectRatio The aspect ratio of the camera.
         * @param nearClip The min distance in which the camera sees objects.
         * @param farClip The max distance in which the camera sees objects.
         */
        PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip);

        /**
         * @brief Returns the ViewProjection matrix.
         * 
         * @returns The ViewProjection of the camera.
         */
        const glm::mat4 &GetViewProjMatrix() const;

        /**
         * @brief Sets the distance of the camera from the focal point.
         * 
         * @param dis The distance to be set.
         */
        void SetDis(float dis);

        /**
         * @brief Sets the focal point of the camera.
         * 
         * @param focalPoint The focal point to be set.
         */
        void SetFocalPoint(const glm::vec3 &focalPoint);

        /**
         * @brief Sets the rotation of the camera.
         * 
         * @param pitch The left/right rotation.
         * @param yaw The up/down rotation.
         */
        void SetPitchYaw(float pitch,float yaw);

        /**
         * @brief Returns the rotation of the camera.
         * 
         * @returns A vector where Pitch is the first value and Yaw the second.
         */
        const glm::vec2 GetPichYaw() const;

        /**
         * @brief Returns the position of the camera in the world.
         * 
         * @returns The position of the camera.
         */
        const glm::vec3 GetPos() const {return m_Pos;};

        /**
         * @brief Returns the focal point of the camera.
         * 
         * @returns The focal point of the camera.
         */
        const glm::vec3 GetFocalPoint() const{ return m_FocalPoint;};

        /**
         * @brief Returns the distance of the camera from  the focal point.
         * 
         * @returns The distance.
         */
        const float GetDis() const{return m_Distance;};
    private:

        /**
         * @brief Recalculates the new view matrix and updates the ViewProjection.
         */
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
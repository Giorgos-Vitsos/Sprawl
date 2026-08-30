#pragma once
#include <glm/glm.hpp>

/**
 * @brief The model matrix wrapper.
 * 
 * Responsible for updating the model matrix of a mesh.
 */
class Transform{
    public:

        /**
         * @brief Initializes the model matrix.
         */
        Transform();

        /**
         * @brief Sets the position of a mesh.
         * 
         * @param pos The pos to be set.
         */
        void SetPos(const glm::vec3& pos);

        /**
         * @brief Sets the rotation of a mesh.
         * 
         * @param rot The rot to be set.
         */
        void SetRot( const glm::vec3& rot);

        /**
         * @brief Sets the scale of a mesh.
         * 
         * @param scale The scale to be set.
         */
        void SetScale( const glm::vec3& scale);

        /**
         * @brief Returns the position of the model.
         * 
         * @returns The position for each axis.
         */
        const glm::vec3& GetPos()  const;

        /**
         * @brief Returns the rotation of the model.
         * 
         * @returns The rotation for each axis.
         */
        const glm::vec3& GetRot()  const;

        /**
         * @brief Returns the scale of the model.
         * 
         * @returns The scale for each axis.
         */
        const glm::vec3& GetScale()  const;

        /**
         * @brief Returns the model matrix.
         * 
         * @returns The model matrix.
         */
        const glm::mat4& GetModelMatrix() const;
    private:
        glm::vec3 m_Pos;
        glm::vec3 m_Rot;
        glm::vec3 m_Scale;
        glm::mat4 m_ModelMatrix;

        /**
         * @brief Recalculates the model matrix by finding the trs.
         */
        void RecalcModelMatrix();
};
#pragma once
#include <glm/glm.hpp>

class Transform{
    public:
        Transform();
        void SetPos(const glm::vec3& pos);
        void SetRot( const glm::vec3& rot);
        void SetScale( const glm::vec3& scale);
        const glm::vec3& GetPos()  const;
        const glm::vec3& GetRot()  const;
        const glm::vec3& GetScale()  const;
        const glm::mat4& GetModelMatrix() const;
    private:
        glm::vec3 m_Pos;
        glm::vec3 m_Rot;
        glm::vec3 m_Scale;
        glm::mat4 m_ModelMatrix;
        void RecalcModelMatrix();
};
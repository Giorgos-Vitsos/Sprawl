#pragma once
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "PerspectiveCamera.h"

class Renderer{
    public:
        void Clear();
        void Draw(Mesh &mesh,Shader &shader,Transform &trs,PerspectiveCamera &camera);
};
#pragma once
#include <glm/glm.hpp>
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "PerspectiveCamera.h"


/**
 * @brief A struct that hold all the stats of the engine.
 */
struct RendererStats{
    int fps;
    int triangles;
    int vertices;
    int calls;
};

/**
 * @brief The heart of the engine.
 * 
 * Responsible for drawing and cleaning the meshes in the window.
 */
class Renderer{
    public:
        /**
         * @brief Enables GL_Depth.
         */
        Renderer();

        /**
         * @brief Resets the window and renderer stats.
         */
        void Clear();

        /**
         * @brief Creates a MVP matrix, draws the mesh and updates the stats.
         * 
         * @param mesh The object we want to render.
         * @param shader The shader to use.
         * @param trs The transform rotation scale matrix of the mesh.
         * @param camera The camera from which the user sees through.
         */
        void Draw(Mesh &mesh,Shader &shader,Transform &trs,PerspectiveCamera &camera);

        /**
         * @brief Returns the engines basic stats.
         * 
         * @returns The stat struct.
         */
        const RendererStats GetStats() { return m_Stats;}

        /**
         * @brief Enables/Disables backface culling.
         * 
         * @param state True to enable and false to disable.
         */
        void ChangeBackFaceCullingState(bool state);

    private:
        RendererStats m_Stats;
};
#pragma once
#include <glm/glm.hpp>
#include "PerspectiveCamera.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

/**
 * @brief Represents a point with colour.
 */
struct DebugVertex{
    glm::vec3 Pos;
    glm::vec3 Color;
};

/**
 * @brief The application's visual debugger.
 *
 * Responsible for initializing a static class with its own GPU buffer objects,
 * drawing the debug visuals (line,grid,cube), rendering them and cleaning the buffers.
 */
class Gizmos{
    public:
        /**
         * @brief Constructor for Gizmos is disabled because its a static class.
         */
        Gizmos()=delete;

        /**
         * @brief Pseudo-constructor creates the GPU buffer objects and connects them.
         */
        static void Init();

        /**
         * @brief Cleans up the GPU buffer objects pointers.
         */
        static void Destroy();

        /**
         * @brief Connects two points by drawing a line.
         * 
         * @param start The first point.
         * @param end The last point.
         * @param color The colour  of the line to be drawn.
         */
        static void DrawLine(const glm::vec3& start,const glm::vec3& end,const glm::vec3& color={0.2f,0.8f,0.6f});

        /**
         * @brief Draws a grid.
         * 
         * @param center Where the grid sits in the world.
         * @param size The number of squares of the grid from top to bottom.
         * @param spacing The distance from each square.
         * @param color The colour of the grid.
         */
        static void DrawGrid(const glm::vec3& center={0,0,0},const float size=100,const int spacing=1,const glm::vec3& color={0.87f,0.87f,0.87f});

        /**
         * @brief Draws a debugging cube.
         * 
         * @param center Where the cube sits in the world.
         * @param size The size of the cube.
         * @param color The colour  of the cube.
         */
        static void DrawWireCube(const glm::vec3& center={0,0,0},const float size=1,const glm::vec3& color={0.2f,0.8f,0.6f});

        /**
         * @brief Renders the whole Gizmos class.
         * 
         * @param camera The camera the user sees through.
         */
        static void Render(PerspectiveCamera &camera);
    private:
        static Shader *s_Shader;
        static VertexArray *s_VAO;
        static VertexBuffer *s_VBO;
        static VertexBufferLayout *s_Layout;
        static std::vector<DebugVertex> s_Vertices;
};
#pragma once
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include <vector>

/**
 * @brief Represents drawable geometry managed by the renderer.
 *
 * A Mesh owns the OpenGL resources required to store and render
 * its geometry: a Vertex Array Object (VAO), Vertex Buffer Object
 * (VBO), and Index Buffer Object (IBO).
 */
class Mesh
{
public:

    /**
     * @brief Creates a mesh from vertex and index data.
     *
     * Uploads the provided vertex and index data to the GPU and
     * configures the vertex array according to the supplied layout.
     *
     * @param vertices Vertex data to upload to the GPU.
     * @param indices Index data used to determine vertex order.
     * @param layout Description of the vertex attributes and their layout.
     */
    Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, const VertexBufferLayout &layout);

    /**
     * @brief Copy construction is disabled.
     */
    Mesh(const Mesh &) = delete;

    /**
     * @brief Copy assignment is disabled.
     */
    Mesh &operator=(const Mesh &) = delete;

    /**
     * @brief Transfers ownership of the mesh's GPU resources.
     */
    Mesh(Mesh &&) = default;

    /**
     * @brief Transfers ownership of the mesh's GPU resources.
     */
    Mesh &operator=(Mesh &&) = default;

    /**
     * @brief Binds the mesh's OpenGL resources.
     *
     * After binding, the mesh's vertex and index data are ready
     * to be used for rendering.
     */
    void Bind() const;

    /**
     * @brief Unbinds the mesh's OpenGL resources.
     *
     * Restores the relevant OpenGL bindings to their default state.
     */
    void Unbind() const;
    
    /**
     * @brief Returns the number of indices used by the mesh.
     *
     * @return Number of indices stored in the index buffer.
     */
    unsigned int GetIndexCount() const;
    unsigned int GetVerticesCount() const;

    void Draw();
private:
    VertexArray m_VAO;
    VertexBuffer m_VBO;
    IndexBuffer m_IBO;
};
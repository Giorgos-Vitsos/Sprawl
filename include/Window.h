#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Renderer.h"
#include <functional>

/**
 * @brief Manages the application's window and OpenGL context.
 *
 * Responsible for initializing GLFW, creating the OpenGL context,
 * loading OpenGL functions through GLAD, processing window events
 * and presenting rendered frames.
 */
class Window
{
public:
    /**
     * @brief Creates a new OpenGL window.
     *
     * @param width  Initial window width.
     * @param height Initial window height.
     * @param title  Window title.
     * @throws runtime_error if GLFW, window creation,
     * or GLAD initialization fails.
     */
    Window(int width, int height, const std::string &title);

    /**
     * @brief Destroys the window and releases resources.
     */
    ~Window();

    /**
     * @brief Checks whether the window should close.
     *
     * @return true if a close request has been received.
     */
    bool ShouldClose() const;

    /**
     * @brief Processes pending window events and presents
     *        the rendered frame.
     *
     * Swaps the front and back buffers and polls GLFW events.
     */
    void SwapBuffersAndPoll();

    /**
     * @brief Processes application input.
     */
    void ProcessInput();

    /**
     * @brief Retrieves the width of the window.
     *
     * @return The total width in pixels.
     */
    int GetWidth() const { return m_Width; }

    /**
     * @brief Retrieves the height of the window.
     *
     * @return The total height in pixels.
     */
    int GetHeight() const { return m_Height; }

    /**
     * @brief Retrieves the GLFWwindow.
     *
     * @return A pointer to the GLFWwindow.
     */
    GLFWwindow *GetWindow() { return m_Window; }

    /**
     * @brief Sets engines stats as window title.
     *
     * @param statStruct The stats of the engine at the current frame.
     */
    void SetStats(RendererStats statStruct);

    /**
     * @brief Enables/Disables VSync.
     *
     * @param statStruct VSync's state. True for enable.
     * @throws runtime_error if GLFWwindow is not set.
     */
    void ChangeVSync(bool VSyncIsOn);

    /**
     * @brief Sets a function to be used as resize callback
     * 
     * @param callback The function to be set.
     */
    void SetResizeCallback(const std::function<void(float)>& callback);

private:
    /**
     * @brief GLFW callback invoked when the framebuffer is resized.
     * @param window The current GLFWwindow.
     * @param width The new width.
     * @param height The new height.
     */
    static void FrameBufferSizeCallBack(GLFWwindow *window, int width, int height);

    /**
     * @brief GLFW callback invoked when the framebuffer is resized.
     * @param id The current GLFWwindow.
     * @param desc The new width.
     * @throws runtime_error if glfwInit fails.
     */
    static void ErrorCallback(int id, const char *desc);
    
    GLFWwindow *m_Window;
    int m_Width;
    int m_Height;
    std::string m_Title;
    static int s_WindowCounter;
    std::function<void(float)> m_ResizeCallback;
};
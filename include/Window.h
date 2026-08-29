#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Renderer.h"

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

    GLFWwindow *GetWindow(){ return m_Window;}
    void SetStats(RendererStats statStruct);
    void ChangeVSync(bool VSyncIsOn);

private:
    /**
     * @brief GLFW callback invoked when the framebuffer is resized.
     */
    static void FrameBufferSizeCallBack(GLFWwindow *window, int width, int height);
    static void ErrorCallback(int id,const char* desc);
    GLFWwindow *m_Window;
    int m_Width;
    int m_Height;
    std::string m_Title;
    static int s_WindowCounter;
};
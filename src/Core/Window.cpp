#include "Window.h"
#include <iostream>
#include <stdexcept>
#include "InputController.h"
#include "OpenGLDebug.h"

Window::Window(int width,int height,const std::string& title):m_Width(width),m_Height(height),m_Title(title),m_Window(nullptr){
    
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW\n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window=glfwCreateWindow(m_Width,m_Height,m_Title.c_str(),nullptr,nullptr);
    
    if (m_Window == NULL)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window\n");
    }

    glfwMakeContextCurrent(m_Window);
    ChangeVSync(true);
    glfwSetFramebufferSizeCallback(m_Window, FrameBufferSizeCallBack);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD\n");
    }
    glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
    glViewport(0, 0, m_Width, m_Height);
    OpenGLDebug::Init();
    InputController::Init(GetWindow());
}

Window::~Window(){

    if(m_Window){
        glfwDestroyWindow(m_Window);
    }
    glfwTerminate();
}

bool Window::ShouldClose() const{

    return glfwWindowShouldClose(m_Window);
}

void Window::SwapBuffersAndPoll(){

    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

void Window::ProcessInput(){

    if (InputController::IsKeyPressed(GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(m_Window, true);
    }
}

void Window::FrameBufferSizeCallBack(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void Window::SetStats(RendererStats statStruct){
    std::string stats="FPS: "+std::to_string(statStruct.fps)+" | "+"Calls: "+std::to_string(statStruct.calls)+" | "+"Triangles: "+std::to_string(statStruct.triangles)+" | "+"Vertices: "+std::to_string(statStruct.vertices); 
    glfwSetWindowTitle(m_Window,stats.c_str());
}

void Window::ChangeVSync(bool VSyncIsOn){
    if(m_Window==nullptr){
        throw std::runtime_error("Cant change VSync if window is not initialized\n");
    }
    if(VSyncIsOn){
        glfwSwapInterval(1);
    }else{
         glfwSwapInterval(0);
    }
};
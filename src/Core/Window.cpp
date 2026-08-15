#include "Window.h"
#include <iostream>
#include <stdexcept>

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
    glfwSetFramebufferSizeCallback(m_Window, FrameBufferSizeCallBack);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD\n");
    }

    glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
    glViewport(0, 0, m_Width, m_Height);
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

    if (glfwGetKey(m_Window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(m_Window, true);
    }
}

void Window::FrameBufferSizeCallBack(GLFWwindow* window, int width, int height){

    glViewport(0, 0, width, height);
}

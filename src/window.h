

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window{
    public:
        Window(int width,int height,const std::string& title);
        ~Window();
        bool ShouldClose() const;
        void SwapBuffersAndPoll();
        void ProcessInput();
        int GetWidth() const { return m_Width;}
        int GetHeight() const {return m_Height;}
    private:
        static void FrameBufferSizeCallBack(GLFWwindow* window,int width,int height);
        GLFWwindow* m_Window;
        int m_Width;
        int m_Height;
        std::string m_Title;
};
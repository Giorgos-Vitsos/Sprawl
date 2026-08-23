#include "TimeHelper.h"
#include <GLFW/glfw3.h>

double TimeHelper::m_CurrentFrame=0;
double TimeHelper::m_LastFrame=0;
double TimeHelper::m_DeltaTime=0;

void TimeHelper::Tick(){
    m_CurrentFrame=glfwGetTime();
    m_DeltaTime=m_CurrentFrame-m_LastFrame;
    m_LastFrame=m_CurrentFrame;
}

double TimeHelper::GetDeltaTime(){ return m_DeltaTime;}
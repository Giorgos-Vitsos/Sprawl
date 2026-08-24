#include "TimeHelper.h"
#include <GLFW/glfw3.h>

double TimeHelper::s_CurrentFrame=0;
double TimeHelper::s_LastFrame=0;
double TimeHelper::s_DeltaTime=0;

void TimeHelper::Tick(){
    s_CurrentFrame=glfwGetTime();
    s_DeltaTime=s_CurrentFrame-s_LastFrame;
    s_LastFrame=s_CurrentFrame;
}

double TimeHelper::GetDeltaTime(){ return s_DeltaTime;}
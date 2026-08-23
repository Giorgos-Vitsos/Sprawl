#pragma once


class TimeHelper{
    private:
        static double m_CurrentFrame;
        static double m_LastFrame;
        static double m_DeltaTime;
    public:
        static void Tick();
        static double GetDeltaTime();
};
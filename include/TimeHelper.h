#pragma once


class TimeHelper{
    private:
        static double s_CurrentFrame;
        static double s_LastFrame;
        static double s_DeltaTime;
    public:
        static void Tick();
        static double GetDeltaTime();
};
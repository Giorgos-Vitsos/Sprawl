#pragma once

/**
 * @brief Helper function that tracks time.
 * 
 * Responsible for tracking time passed from
 * last frame so that we can use delta Time.
 */
class TimeHelper{
    private:
        static double s_CurrentFrame;
        static double s_LastFrame;
        static double s_DeltaTime;
    public:
        /**
         * @brief Updates the time passed and updates deltaTime.
         */
        static void Tick();

        /**
         * @brief Returns the deltaTime.
         * 
         * @returns The deltaTime.
         */
        static double GetDeltaTime();
};
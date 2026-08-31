#pragma once
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

/**
 * @brief Manages the users inputs and aplication controlls.
 *
 * Responsible for initializing cursor positon,
 * reading mouse movement and keyboard keystrokes.
 */
class InputController{
    public:
        /**
         * @brief Initializes cursors's position and connects scrollcallback.
         * 
         * @param window The window from which we read inputs.
         */
        static void Init(GLFWwindow *window);

        /**
         * @brief Constructor is disable because class is static.
         */
        InputController()=delete;

        /**
         * @brief Tells if a specific key is pressed.
         * 
         * @param keycode The id of the keystroke.
         * @return True if the key has been pressed.
         */
        static bool IsKeyPressed(int keycode);

        /**
         * @brief Tells if a specific mouse button is pressed.
         * 
         * @param button The id of the button.
         * @return True if the button has been pressed.
         */
        static bool IsMouseButtonPressed(int button);

        /**
         * @brief Reads the mouse position and finds the movement.
         * 
         * @return The location of the cursos based on the last frame.
         */
        static glm::vec2 GetMouseDelta();

        /**
         * @brief Reads the mouse scrolls and translates them.
         * 
         * @return The scroll movement.
         */
        static double GetScrollDeltaY();

        /**
         * @brief The behaviour of the scroll wheel when called.
         * 
         * @param window The current GLFWwindow.
         * @param xoffset The horizontal movement.
         * @param yoffset The vertical movement
         */
        static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    private:
        static GLFWwindow *s_Window;
        static double s_LastY;
        static double s_LastX;
        static double s_ScrollDeltaY;
};
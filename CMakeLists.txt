cmake_minimum_required(VERSION 3.15)
project(GraphicsEngine VERSION 1.0)

# Enforce modern C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the system's OpenGL libraries
find_package(OpenGL REQUIRED)

# Automatically fetch and build GLFW
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
)

# Disable GLFW extras to speed up your build
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# Define your engine executable
add_executable(Engine
    src/main.cpp
    src/glad.c
)

# Tell CMake to look in the 'include' folder for header files
target_include_directories(Engine PRIVATE include)

# Link your executable to GLFW and OpenGL
target_link_libraries(Engine PRIVATE glfw OpenGL::GL)

# Create a custom 'run' target
add_custom_target(run
    COMMAND $<TARGET_FILE:Engine>
    DEPENDS Engine
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
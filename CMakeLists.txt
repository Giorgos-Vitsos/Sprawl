cmake_minimum_required(VERSION 3.15)
project(GraphicsEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# Define your engine executable
add_executable(Engine
    src/Core/main.cpp
    src/Core/Window.cpp
    src/Renderer/OrthographicCamera.cpp
    src/Renderer/VertexBuffer.cpp
    src/Renderer/VertexArray.cpp
    src/glad.c
    src/Renderer/Shader.cpp
    src/Renderer/IndexBuffer.cpp
    src/Renderer/Mesh.cpp
    src/Renderer/PrimitiveCreator.cpp
    src/Renderer/Transform.cpp
)

# Tell CMake to look in the 'include' folder for header files
target_include_directories(Engine PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/vendors
)

# Link your executable to GLFW and OpenGL
target_link_libraries(Engine PRIVATE glfw OpenGL::GL)

# Create a custom 'run' target
add_custom_target(run
    COMMAND $<TARGET_FILE:Engine>
    DEPENDS Engine
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
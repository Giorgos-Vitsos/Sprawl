cmake_minimum_required(VERSION 3.15)
project(SprawlEngine VERSION 1.0)

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
file(GLOB_RECURSE ENGINE_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

add_executable(Engine
    ${ENGINE_SOURCES}
)

# Tell CMake to look in the 'include' folder for header files
target_include_directories(Engine PRIVATE
    ${CMAKE_SOURCE_DIR}/vendors
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/Core
    ${CMAKE_SOURCE_DIR}/include/Renderer
    ${CMAKE_SOURCE_DIR}/include/Scene
)

# Link your executable to GLFW and OpenGL
target_link_libraries(Engine PRIVATE glfw OpenGL::GL)

if(MSVC)
    # Disables incremental linking specifically for Debug builds
    target_link_options(Engine PRIVATE "$<$<CONFIG:Debug>:/INCREMENTAL:NO>")
endif()

# Create a custom 'run' target
add_custom_target(run
    COMMAND $<TARGET_FILE:Engine>
    DEPENDS Engine
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    USES_TERMINAL
)
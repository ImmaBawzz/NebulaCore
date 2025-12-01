cmake_minimum_required(VERSION 3.10)
project(NebulaCore VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
)
FetchContent_MakeAvailable(glfw)

# --- Engine Library ---
file(GLOB_RECURSE ENGINE_SOURCES
    "engine/core/*.cpp"
    "engine/rendering/*.cpp"
    "engine/scene/*.cpp"
    "engine/scripting/*.cpp"
    "engine/plugins/*.cpp"
)

add_library(NebulaCore STATIC ${ENGINE_SOURCES})
target_include_directories(NebulaCore PUBLIC engine)
target_link_libraries(NebulaCore PUBLIC glfw)

# --- Sandbox Game ---
add_executable(sandbox_game examples/sandbox_game/main.cpp)
target_link_libraries(sandbox_game PRIVATE NebulaCore)

# --- CLI Tool ---
add_executable(nebula_tool tools/cli/nebula_tool.cpp)

# --- Tests ---
enable_testing()
add_executable(core_tests tests/core_tests.cpp)
target_link_libraries(core_tests PRIVATE NebulaCore)
add_test(NAME CoreTests COMMAND core_tests)

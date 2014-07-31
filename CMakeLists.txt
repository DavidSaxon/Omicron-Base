cmake_minimum_required(VERSION 2.6)
project(TestRun)

set(SRCS

    src/omicron/Omicron.cpp
    src/omicron/display/Window.cpp
    src/omicron/entity/ComponentTable.cpp
    src/omicron/logic/FPSManager.cpp
    src/omicron/logic/LogicManager.cpp
    src/omicron/rendering/Renderer.cpp
    src/omicron/scene/Scene.cpp
    src/omicron/settings/DisplaySettings.cpp
    src/omicron/settings/RenderSettings.cpp
    src/omicron/system/System.cpp
    src/override/start_up/StartUp.cpp

    src/scenes/TestScene.cpp

    src/entities/test/TestEntity.cpp
)

set(BASEPATH "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++0x -DGL_GLEXT_PROTOTYPES")

include_directories("${BASEPATH}" ${INCLUDE_DIRECTORIES})

link_directories(${LINK_DIRECTORIES})

add_executable(TestRun ${SRCS})

target_link_libraries(TestRun

    -lGL
    -lGLU
    -lglut
    -lm
    -lpng
)

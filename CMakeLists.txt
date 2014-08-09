cmake_minimum_required(VERSION 2.6)
project(TestRun)

set(SRCS

    src/omicron/Omicron.cpp
    src/omicron/component/renderable/Mesh.cpp
    src/omicron/component/renderable/Sprite.cpp
    src/omicron/display/Window.cpp
    src/omicron/entity/ComponentTable.cpp
    src/omicron/logic/FPSManager.cpp
    src/omicron/logic/LogicManager.cpp
    src/omicron/rendering/Renderer.cpp
    src/omicron/rendering/RenderLists.cpp
    src/omicron/rendering/shading/Material.cpp
    src/omicron/rendering/shading/Shader.cpp
    src/omicron/rendering/shading/Texture.cpp
    src/omicron/resource/loader/GeometryLoader.cpp
    src/omicron/resource/loader/ShaderLoader.cpp
    src/omicron/resource/loader/TextureLoader.cpp
    src/omicron/resource/type/TextureResource.cpp
    src/omicron/resource/ResourceManager.cpp
    src/omicron/scene/Scene.cpp
    src/omicron/settings/DisplaySettings.cpp
    src/omicron/settings/RenderSettings.cpp
    src/omicron/system/System.cpp
    src/override/StartUp.cpp

    src/scenes/TestScene.cpp

    src/entities/test/Skybox.cpp
    src/entities/test/SpriteTest.cpp
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
    -lGLEW
    -lm
    -lpng
    -lIL
)

#include "Skybox.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Skybox::init() {

    // load some geometry yo
    omi::Geometry* geo =
        omi::loader::geoFromWavefront("res/gfx/geometry/test/skybox.obj");

    // load a texture
    omi::Texture* texture =
        omi::loader::textureFromImage("res/gfx/texture/test/skybox.png");

    // load a shader
    omi::Shader shader = omi::loader::loadShaderFromFiles(
        "res/gfx/shader/test/test_vertex.glsl",
        "res/gfx/shader/test/test_fragment.glsl");

    // create a material
    omi::Material material(
            shader, util::vec::Vector4(1.0f, 1.0f, 1.0f, 1.0f), texture);

    // memory leaks!

    // add a mesh
    m_components.add(
        new omi::Mesh(
            "skybox",
            0,
            dynamic_cast<omi::Transform*>(m_components.get("transform")),
            geo,
            material
        )
    );
}

void Skybox::update() {
}

#include "Skybox.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Skybox::init() {

    // load some geometry yo
    omi::Geometry* geo =
        omi::loader::geoFromWavefront("res/gfx/geometry/test/skybox.obj");

    // load a texture
    omi::Texture texture =
        omi::loader::textureFromImage("res/gfx/texture/test/skybox.png");

    // create a material
    omi::Material* material = new omi::Material(
            util::vec::Vector4(1.0f, 1.0f, 1.0f, 1.0f), texture);

    // memory leaks!

    // add a mesh
    m_components.add(
        new omi::Mesh(
            "skybox",
            dynamic_cast<omi::Transform*>(m_components.get("transform")),
            geo,
            material
        )
    );
}

void Skybox::update() {
}
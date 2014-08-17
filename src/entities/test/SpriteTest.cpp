#include "SpriteTest.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void SpriteTest::init() {

    omi::Transform* transform =
        dynamic_cast<omi::Transform*>(m_components.get("transform"));
    transform->scale = util::vec::Vector3(4.0f, 4.0f, 4.0f);

    // load a texture
    omi::Texture texture =
        omi::loader::textureFromImage("res/gfx/texture/test/sprite_test.png");

    // load a shader
    omi::Shader shader = omi::loader::loadShaderFromFiles(
        "res/gfx/shader/test/test_vertex.glsl",
        "res/gfx/shader/test/test_fragment.glsl");

    // create a material
    omi::Material material(
            shader, util::vec::Vector4(1.0f, 1.0f, 1.0f, 1.0f), texture);

    // add a sprite
    m_components.add(
        new omi::Sprite(
            "sprite",
            2,
            transform,
            material,
            util::vec::Vector2(10.0, 10.0)
        )
    );
}

void SpriteTest::update() {
}

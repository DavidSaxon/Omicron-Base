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
    m_sprite = new omi::Sprite(
        "sprite",
        2,
        transform,
        material,
        util::vec::Vector2(2.0, 2.0),
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(0.0, 0.0)
    );

    m_components.add(m_sprite);
}

void SpriteTest::update() {

    // shift the texture
    util::vec::Vector2 texOffset = m_sprite->getTexOffset();

    texOffset.x += 0.01f * omi::fpsManager.getTimeScale();
    if (texOffset.x >= 1.0f) {

        texOffset.x -= 1.0f;
    }

    texOffset.y += 0.01f * omi::fpsManager.getTimeScale();
    if (texOffset.y >= 1.0f) {

        texOffset.y -= 1.0f;
    }

    m_sprite->setTexOffset(texOffset);
}

#include "SpriteTest.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void SpriteTest::init() {

    omi::Transform* transform =
        dynamic_cast<omi::Transform*>(m_components.get("transform"));

    // load animation
    omi::Texture* tex = omi::loader::animationFromImage(
        "res/gfx/texture/test/explosion_1/explosion.png", 55, true, 1, 12);

    // create material
    omi::Material material(omi::ResourceManager::getShader("test_shader"),
        util::vec::Vector4(1, 1, 1, 1), tex);

    m_sprite = new omi::Sprite(
        "sprite", 2, transform, material,
        util::vec::Vector2(4, 4),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );

    m_components.add(m_sprite);
}

void SpriteTest::update() {
}

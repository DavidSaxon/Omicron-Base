#include "SpriteTest.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void SpriteTest::init() {

    omi::Transform* transform =
        dynamic_cast<omi::Transform*>(m_components.get("transform"));
    // transform->scale = util::vec::Vector3(4.0f, 4.0f, 4.0f);

    // add a sprite
    m_sprite = omi::ResourceManager::getSprite(
        "test_sprite", "sprite", transform);

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

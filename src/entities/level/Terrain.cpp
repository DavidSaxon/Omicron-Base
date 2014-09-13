#include "Terrain.hpp"

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

namespace {

    static const unsigned PLANE_COUNT = 3;
    static const float    PLANE_SIZE = 65.0f;
    static const float    MOVE_SPEED = 0.1f;

}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Terrain::init() {

    // add the ground planes
    for (unsigned i = 0; i < PLANE_COUNT; ++i) {

        // transform
        omi::Transform* transform = new omi::Transform(
            "",
            util::vec::Vector3(0.0f, i * PLANE_SIZE, 0.0f),
            util::vec::Vector3(),
            util::vec::Vector3(1.0f, 1.0f, 1.0f)
        );
        m_transforms.push_back(transform);
        m_components.add(transform);

        // sprite
        omi::Sprite* sprite = omi::ResourceManager::getSprite(
            "terrain_grass_1", "", transform);
        m_sprites.push_back(sprite);
        m_components.add(sprite);
    }

}

void Terrain::update() {

    // scroll the terrain down
    float moveSpeed = MOVE_SPEED * omi::fpsManager.getTimeScale();
    for (std::vector<omi::Transform*>::iterator it = m_transforms.begin();
         it != m_transforms.end(); ++it) {

        (*it)->translation.y -= moveSpeed;
        // shift up if it has gone past the user's view
        if ((*it)->translation.y < -PLANE_SIZE) {

            (*it)->translation.y += PLANE_SIZE * PLANE_COUNT;
        }
    }
}


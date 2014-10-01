#include "Packs.hpp"

namespace pack {

void buildShipPack()
{
    //--------------------------------------------------------------------------
    //                                  SPRITES
    //--------------------------------------------------------------------------

    //-----------------------------------HULL-----------------------------------

    //steel
    omi::ResourceManager::addTextureMaterialSprite(
        "ship_hull_steel", resource_group::SHIP,
        "test_shader",
        "res/gfx/texture/ship/hull/steel/steel.png",
        1, true, 1, 5,
        layer::SHIP_HULL,
        glm::vec2( 1, 1 ),
        glm::vec2( 1, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::CLAMP | omi::texture::SHOW_PIXELS
    );

    //----------------------------------WEAPON----------------------------------

    // rocket launcher
    omi::ResourceManager::addTextureMaterialSprite(
        "ship_weapon_rocket_launcher", resource_group::SHIP,
        "test_shader",
        "res/gfx/texture/ship/weapon/rocket_launcher.png",
        layer::SHIP_WEAPON,
        glm::vec2( 1, 1 ),
        glm::vec2( 1, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::CLAMP | omi::texture::SHOW_PIXELS
    );

    //----------------------------------ENGINE----------------------------------

    // coal
    omi::ResourceManager::addTextureMaterialSprite(
        "ship_engine_coal", resource_group::SHIP,
        "test_shader",
        "res/gfx/texture/ship/engine/coal.png",
        layer::SHIP_ENGINE,
        glm::vec2( 1, 1 ),
        glm::vec2( 1, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::CLAMP | omi::texture::SHOW_PIXELS
    );
}

} // namespace pack

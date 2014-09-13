#include "Packs.hpp"

namespace pack {
    
void buildLevelPack() {

    //--------------------------------------------------------------------------
    //                                  SPRITES
    //--------------------------------------------------------------------------

    //---------------------------------TERRAIN----------------------------------

    // GRASS 1
    omi::ResourceManager::addTextureMaterialSprite(
        "terrain_grass_1", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/terrain/grass_1.png", TERRAIN,
        util::vec::Vector2(65, 65),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );

    //----------------------------------BLOCKS----------------------------------

    // HUB PLAYER
    omi::ResourceManager::addTextureMaterialSprite(
        "block_hub_player", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/block/hub_player.png", SHIP_BLOCK,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
    // STEEL
    omi::ResourceManager::addTextureMaterialSprite(
        "block_steel", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/block/steel.png", SHIP_BLOCK,
        util::vec::Vector2(1.0, 1.0),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
}

} // namespace pack
#include "Packs.hpp"

namespace pack {
    
void buildLevelPack() {

    //--------------------------------------------------------------------------
    //                                  SPRITES
    //--------------------------------------------------------------------------

    //----------------------------------BLOCKS----------------------------------

    // omicron logo text bottom
    omi::ResourceManager::addTextureMaterialSprite(
        "block_steel", resource_group::LEVEL,
        "default_shader",
        "res/gfx/texture/level/ship/block/steel.png", SHIP_BLOCK,
        util::vec::Vector2(1, 1),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
}

} // namespace pack
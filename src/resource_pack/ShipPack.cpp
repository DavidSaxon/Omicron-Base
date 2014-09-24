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
        util::vec::Vector2(1, 1),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0),
        omi::texture::CLAMP | omi::texture::SHOW_PIXELS
    );
}

} // namespace pack

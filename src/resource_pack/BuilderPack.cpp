#include "Packs.hpp"

namespace pack {

void buildBuilderPack()
{
    //---------------------------------SPRITES----------------------------------
        omi::ResourceManager::addTextureMaterialSprite(
        "builder_background", resource_group::BUILDER,
        "test_shader",
        "res/gfx/texture/builder/background.png",
        layer::BACKGROUND,
        util::vec::Vector2( 96, 96 ),
        util::vec::Vector2( 6, 6 ),
        util::vec::Vector2( 0, 0 ),
        omi::texture::SHOW_PIXELS,
        omi::material::SHADELESS
    );
}

} // namespace pack

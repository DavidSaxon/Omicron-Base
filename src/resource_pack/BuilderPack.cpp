#include "Packs.hpp"

namespace pack {

void buildBuilderPack()
{
    //---------------------------------SPRITES----------------------------------
        omi::ResourceManager::addTextureMaterialSprite(
        "builder_background", resource_group::BUILDER,
        "test_shader",
        "res/gfx/texture/builder/background.png",
        builder::BACKGROUND,
        util::vec::Vector2(16, 16),
        util::vec::Vector2(1, 1),
        util::vec::Vector2(0, 0)
    );
}

} // namespace pack
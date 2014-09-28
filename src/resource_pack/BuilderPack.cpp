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
        glm::vec2( 96, 96 ),
        glm::vec2( 2, 2 ),
        glm::vec2( 0, 0 ),
        omi::texture::SHOW_PIXELS,
        omi::material::SHADELESS
    );
}

} // namespace pack

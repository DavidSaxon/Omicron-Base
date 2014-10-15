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

    // block select
    omi::ResourceManager::addTextureMaterialSprite(
        "builder_block_select", resource_group::BUILDER,
        "test_shader",
        "res/gfx/texture/builder/block_select.png",
        layer::BUILDER_SELECT_OUTLINE,
        glm::vec2( 1, 1 ),
        glm::vec2( 1, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::CLAMP | omi::texture::SHOW_PIXELS,
        omi::material::SHADELESS
    );
    // connection arrow
    omi::ResourceManager::addTextureMaterialSprite(
        "builder_connection_arrow", resource_group::BUILDER,
        "test_shader",
        "res/gfx/texture/builder/connection_arrow.png",
        layer::BUILDER_CONNECTION_ARROW,
        glm::vec2( 2, 2 ),
        glm::vec2( 1, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::CLAMP | omi::texture::SHOW_PIXELS,
        omi::material::SHADELESS
    );

    // horizontal boundary scaffold
    omi::ResourceManager::addTextureMaterialSprite(
        "builder_boundary_scaffold_horizontal", resource_group::BUILDER,
        "test_shader",
        "res/gfx/texture/builder/boundary_scaffold_horizontal.png",
        layer::BOUNDARY,
        glm::vec2( 96, 1 ),
        glm::vec2( 96, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::SHOW_PIXELS
    );
    // vertical boundary scaffold
    omi::ResourceManager::addTextureMaterialSprite(
        "builder_boundary_scaffold_vertical", resource_group::BUILDER,
        "test_shader",
        "res/gfx/texture/builder/boundary_scaffold_vertical.png",
        layer::BOUNDARY,
        glm::vec2( 1, 96 ),
        glm::vec2( 1, 96 ),
        glm::vec2( 0, 0 ),
        omi::texture::SHOW_PIXELS
    );
    // scaffold cog
    omi::ResourceManager::addTextureMaterialSprite(
        "builder_boundary_scaffold_cog", resource_group::BUILDER,
        "test_shader",
        "res/gfx/texture/builder/scaffold_cog.png",
        layer::BOUNDARY,
        glm::vec2( 1, 1 ),
        glm::vec2( 1, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::SHOW_PIXELS
    );
    // scaffold cog
    omi::ResourceManager::addTextureMaterialSprite(
        "builder_boundary_scaffold_cog_holder", resource_group::BUILDER,
        "test_shader",
        "res/gfx/texture/builder/scaffold_cog_holder.png",
        layer::BOUNDARY_1,
        glm::vec2( 1, 1 ),
        glm::vec2( 1, 1 ),
        glm::vec2( 0, 0 ),
        omi::texture::SHOW_PIXELS
    );
}

} // namespace pack

#include "Packs.hpp"

namespace pack {

void buildTestBack() {

    omi::ResourceManager::addTexture(
        "test_brick",
        resource_group::TEST,
        "res/gfx/texture/test/brick.png"
    );
}

} // namespace pack
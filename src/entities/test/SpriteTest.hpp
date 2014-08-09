#ifndef OMICRON_ENTITIES_TEST_SPRITETEST_H_
#   define OMICRON_ENTITIES_TEST_SPRITETEST_H_

#include "src/omicron/entity/Entity.hpp"

#include "src/omicron/rendering/shading/Material.hpp"
#include "src/omicron/resource/loader/Loaders.hpp"

class SpriteTest : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
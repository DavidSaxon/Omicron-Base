#ifndef OMICRON_ENTITIES_TEST_TESTENTITY_H_
#   define OMICRON_ENTITIES_TEST_TESTENTITY_H_

#include <cmath>
#include <iostream>

#include "src/omicron/entity/Entity.hpp"

#include "src/omicron/rendering/shading/Material.hpp"
#include "src/omicron/resource/loader/Loaders.hpp"

class TestEntity : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the position of this entity
    omi::Transform* m_transform;

    // sine counter
    float m_sineCounter;
};

#endif

#ifndef OMICRON_ENTITIES_TEST_TESTENTITY_H_
#   define OMICRON_ENTITIES_TEST_TESTENTITY_H_

#include <cmath>
#include <iostream>

#include "src/entities/test/BoxTrail.hpp"
#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/resource/ResourceManager.hpp"

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

    // counter
    unsigned m_counter;
    // sine counter
    float m_sineCounter;
};

#endif

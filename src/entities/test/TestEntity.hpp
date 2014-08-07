#ifndef OMICRON_ENTITIES_TEST_TEST_ENTITY_H_
#   define OMICRON_ENTITIES_TEST_TEST_ENTITY_H_

#include <cmath>

#include "src/omicron/entity/Entity.hpp"

#include "src/omicron/resource/loader/GeometryLoader.hpp"

class TestEntity : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    TestEntity();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~TestEntity();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

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

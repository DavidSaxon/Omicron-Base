#ifndef OMICRON_ENTITIES_TEST_TEST_ENTITY_H_
#   define OMICRON_ENTITIES_TEST_TEST_ENTITY_H_

#include <iostream>

#include "src/omicron/logic/entity/Entity.hpp"

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

    void update();

};

#endif

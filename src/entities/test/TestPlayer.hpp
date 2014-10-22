#ifndef OMICRON_ENTITIES_TEST_TESTPLAYER_HPP_
#   define OMICRON_ENTITIES_TEST_TESTPLAYER_HPP_

#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/input/Input.hpp"

class TestPlayer : public omi::Entity {
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

    // the transform of the camera
    omi::Transform* m_camT;
};

#endif

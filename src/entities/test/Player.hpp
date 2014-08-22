#ifndef OMICRON_TEST_PLAYER_H_
#    define OMICRON_TEST_PLAYER_H_

#include "lib/Utilitron/MathUtil.hpp"

#include "src/entities/test/TestEntity.hpp"
#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/input/Input.hpp"

class Player : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Player();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Player();

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

    // is true if the shoot button is down
    bool m_shootButton;
};

#endif

#ifndef BOF_LEVEL_PLAYERSHIP_H_
#    define BOF_LEVEL_PLAYERSHIP_H_

#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/input/Input.hpp"

#include "src/entities/level/block/PlayerHub.hpp"

class PlayerShip : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    PlayerShip();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~PlayerShip();

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
    // the transform of the ship
    omi::Transform* m_shipT;

    // the hub of the ship
    PlayerHub* m_hub;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void processInput();

    void movement();

    void initComponents();
};

#endif

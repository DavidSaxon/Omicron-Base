#ifndef OMICRON_ENTITIES_START_UP_STARTUPCAMERA_H_
#   define OMICRON_ENTITIES_START_UP_STARTUPCAMERA_H_

#include "src/omicron/entity/Entity.hpp"

class StartUpCamera : public omi::Entity {
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

    // the position of the camera
    omi::Transform* m_transform;
};

#endif

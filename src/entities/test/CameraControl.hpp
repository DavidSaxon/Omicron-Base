#ifndef OMICRON_ENTITIES_TEST_CAMERA_CONTROL_H_
#   define OMICRON_ENTITIES_TEST_CAMERA_CONTROL_H_

#include "src/omicron/entity/Entity.hpp"

class CameraControl : public omi::Entity {
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
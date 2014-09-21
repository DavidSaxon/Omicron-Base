#ifndef VOIDWALKER_BUILDER_BUILDERCONTROL_H_
#    define VOIDWALKER_BUILDER_BUILDERCONTROL_H_

#include "src/omicron/entity/Entity.hpp"

/************************************************************************\
| The entity that handles control elements in the builder scene: such as |
| camera and music.                                                      |
\************************************************************************/
class BuilderControl : public omi::Entity {
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

    // the transformation of the camera
    omi::Transform* m_camT;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Initialises the components */
    void initComponents();
};

#endif

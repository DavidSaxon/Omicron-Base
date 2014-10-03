#ifndef VOIDWALKER_GUI_CURSOR_H_
#    define VOIDWALKER_GUI_CURSOR_H_

#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/input/Input.hpp"
#include "src/omicron/utilities/TransformUtil.hpp"

class Cursor : public omi::Entity {
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

    omi::Transform* m_transform;

};

#endif

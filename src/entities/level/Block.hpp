#ifndef BOF_LEVEL_BLOCK_H_
#    define BOF_LEVEL_BLOCK_H_

#include "src/omicron/entity/Entity.hpp"

class Block : public omi::Entity {
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

    // the transform of the block
    omi::Transform* m_transform;

    // the collision detector of the block
    omi::CollisionDetector* m_collisionDetect;
};

#endif

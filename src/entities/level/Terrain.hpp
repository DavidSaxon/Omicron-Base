#ifndef BOF_LEVEL_TERRAIN_H_
#    define BOF_LEVEL_TERRAIN_H_

#include <vector>

#include "src/omicron/entity/Entity.hpp"

class Terrain : public omi::Entity {
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

    // the positions of the sprites
    std::vector<omi::Transform*> m_transforms;

    // the sprites
    std::vector<omi::Sprite*> m_sprites;
};

#endif

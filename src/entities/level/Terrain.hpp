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
    omi::Transform* m_pos_1;
    omi::Transform* m_pos_2;
    omi::Transform* m_pos_3;
    std::vector<omi::Transform*> m_transforms;

    // the sprites
    omi::Sprite* m_sprite_1;
    omi::Sprite* m_sprite_2;
    omi::Sprite* m_sprite_3;
    std::vector<omi::Sprite*> m_sprites;
};

#endif

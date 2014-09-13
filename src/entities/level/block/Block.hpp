#ifndef BOF_LEVEL_BLOCK_BLOCK_H_
#    define BOF_LEVEL_BLOCK_BLOCK_H_

#include "src/omicron/entity/Entity.hpp"

namespace block {

enum Owner {

    NONE,
    PLAYER,
    ENEMY
};

} // namespace block

class Block : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // if the block has been traversed this iteration
    bool traversed;

    // the neighbors of the block
    Block* top;
    Block* bottom;
    Block* left;
    Block* right;

    // the collision detector of the block
    omi::CollisionDetector* m_collisionDetect;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Block(
            const std::string& sprite,
            const util::vec::Vector3& pos,
                  block::Owner         owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Block();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void init();

    /** #Override */
    virtual void update();

    void setPosition(const util::vec::Vector3& pos);

    /** Renews the travsel state of this block */
    void renew();

    //---------------------------------GETTERSA---------------------------------

    /** @return the owner of the block */
    block::Owner getOwner() const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the owner of the block
    block::Owner m_owner;

    // the transform of the block
    omi::Transform* m_transform;
    // the name of the sprite
    std::string m_spriteName;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void noOwnerUpdate();
};

#endif

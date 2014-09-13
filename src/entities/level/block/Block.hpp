#ifndef BOF_LEVEL_BLOCK_BLOCK_H_
#    define BOF_LEVEL_BLOCK_BLOCK_H_

#include "src/omicron/entity/Entity.hpp"

namespace block {

enum Owner {

    NONE,
    PLAYER,
    ENEMY
};

enum State {

    NOT_ATTACHED,
    ATTACHING,
    ATTACHED
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

    // the transform of the block
    omi::Transform* m_transform;
    // the collision detector of the block
    omi::CollisionDetector* m_collisionDetect;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Block(
            const std::string& sprite, const std::string& weapon,
            const std::string& engine, const std::string& trail,
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

    virtual void setPosition(const util::vec::Vector3& pos);

    /** Renews the travsel state of this block */
    void renew();

    void attach(bool a);

    //---------------------------------GETTERSA---------------------------------

    /** @return the owner of the block */
    block::Owner getOwner() const;

    //---------------------------------SETTERS----------------------------------

    void setOwner(block::Owner owner);

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the owner of the block
    block::Owner m_owner;
    // the state of the block
    block::State m_state;

    // the name of the sprite
    std::string m_spriteName;

    omi::Transform* m_weaponT;
    omi::Sprite* m_weaponSprite;
    std::string m_weaponName;
    util::vec::Vector3 m_weaponOffset;

    omi::Transform* m_engineT;
    omi::Sprite* m_engineSprite;
    std::string m_engineName;
    util::vec::Vector3 m_engineOffset;

    omi::Transform* m_trailT;
    omi::Sprite* m_trailSprite;
    std::string m_trailName;

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void noOwnerUpdate();
};

#endif

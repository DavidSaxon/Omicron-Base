#ifndef OMICRON_ENTITY_ENTITY_H_
#   define OMICRON_ENTITY_ENTITY_H_

#include <vector>

#include "src/omicron/Omicron.hpp"
#include "src/omicron/component/Component.hpp"
#include "src/omicron/entity/ComponentTable.hpp"
#include "src/omicron/resource/ResourceManager.hpp"

// here we are including all known components so the user doesn't have to
#include "src/omicron/component/Transform.hpp"
#include "src/omicron/component/renderable/Mesh.hpp"
#include "src/omicron/component/renderable/Sprite.hpp"

namespace omi {

/****************************************************\
| Abstract base class that all entities will extend. |
\****************************************************/
class Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Entity super constructor */
    Entity() {

        // create a transform at origin
        m_components.add(
            new omi::Transform(
                "transform",
                util::vec::Vector3(),
                util::vec::Vector3(),
                util::vec::Vector3(1.0f, 1.0f, 1.0f)
            )
        );
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Entity() {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** initialises the entity */
    virtual void init() = 0;

    /** Updates the entity and computes it's logic */
    virtual void update() = 0;

    /** @return the component table of this entity */
    ComponentTable& getComponents() {

        return m_components;
    }

    /** #Hidden
    @return the entities add list */
    std::vector<Entity*>& getAddList() {

        return m_addList;
    }

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the table of components this entity has
    ComponentTable m_components;

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Adds a new entity to the current scene
    @param entity a pointer to the new entity */
    void addEntity(Entity* entity) {

        m_addList.push_back(entity);
    }

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the list of new entities created by this entity this frame
    std::vector<Entity*> m_addList;
};

} // namespace omi

#endif

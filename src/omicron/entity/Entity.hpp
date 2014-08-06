#ifndef OMICRON_ENTITY_ENTITY_H_
#   define OMICRON_ENTITY_ENTITY_H_

#include "src/omicron/entity/ComponentTable.hpp"
#include "src/omicron/entity/component/Component.hpp"

// here we are including all known components so the user doesn't have to
#include "src/omicron/entity/component/Transform.hpp"
#include "src/omicron/entity/component/renderable/Mesh.hpp"

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
                util::vec::Vector3()
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

    /** @return the component table of this entity */
    virtual ComponentTable& getComponents() {

        return m_components;
    }

    /** Updates the entity and computes it's logic */
    virtual void update() = 0;

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the table of components this entity has
    ComponentTable m_components;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    // TODO: component update

    // TODO: clean up
};

} // namespace omi

#endif

#ifndef OMICRON_ENTITY_ENTITY_H_
#   define OMICRON_ENTITY_ENTITY_H_

#include "src/omicron/entity/ComponentTable.hpp"
#include "src/omicron/entity/component/Component.hpp"

// here we are including all known components so the user doesn't have to
#include "src/omicron/entity/component/Transform.hpp"

namespace omi {

/****************************************************\
| Abstract base class that all entities will extend. |
\****************************************************/
class Entity {
public:

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Entity() {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

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

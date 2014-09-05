#ifndef OMICRON_COMPONENT_COMPONENT_H_
#   define OMICRON_COMPONENT_COMPONENT_H_

#include <sstream>
#include <string>

#include "lib/Utilitron/MacroUtil.hpp"

namespace omi {

namespace component {

//! the different possible types of component
enum Type {

    SIMPLE,     // a component that requires no updating
    UPDATABLE,  // a component that should be updated once per logic cycle
    RENDERABLE, // a component that should be updated by the renderer
    CAMERA      // a component that is used by the render for perspective
};

} // namespace component

/***********************************************************************\
| Abstract base class for any object that can be attached to an entity. |
\***********************************************************************/
class Component {
public:

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Component() {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** @return the identifier of the component */
    const std::string& getId() const {

        return m_id;
    }

    /** @return the type of the component */
    virtual component::Type getType() const {

        return component::SIMPLE;
    }

protected:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a new component
    @param id the identifier of the component */
    Component(const std::string& id) :
        m_id(id) {

            // if an id hasn't been defined just serialise the pointer of this
            if (!m_id.length()) {

                std::stringstream ss;
                ss << this;
                m_id = ss.str();
            }
    }

    Component(const Component&) {
    }

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the identifier of the component which must be unique to the entity
    std::string m_id;
};

} // namespace omi

#endif

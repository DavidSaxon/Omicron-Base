#ifndef OMICRON_ENTITY_COMPONENT_H_
#   define OMICRON_ENTITY_COMPONENT_H_

#include <string>

#include "lib/Utilitron/MacroUtil.hpp"

namespace omi {

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

    /**@return the identifier of the component*/
    const std::string& getId() const {

        return m_id;
    }

protected:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /**Creates a new component
    @param id the identifier of the component*/
    Component(const std::string& id) :
        m_id(id) {
    }

    Component(const Component&) {
    }

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //the identifier of the component which must be unique to the entity
    std::string m_id;
};

} //namespace omi

#endif

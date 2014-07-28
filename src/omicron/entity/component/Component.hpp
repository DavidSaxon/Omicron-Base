#ifndef OMICRON_ENTITY_COMPONENT_H_
#   define OMICRON_ENTITY_COMPONENT_H_

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

protected:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    virtual Component() = 0;

    virtual Component(const Component&) = 0;
};

} //namespace omi

#endif

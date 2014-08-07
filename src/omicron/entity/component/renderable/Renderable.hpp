#ifndef OMICRON_ENTITY_COMPONENT_RENDERABLE_RENDERABLE_H_
#   define OMICRON_ENTITY_COMPONENT_RENDERABLE_RENDERABLE_H_

#include <GL/glut.h>

#include "src/omicron/entity/component/Component.hpp"

namespace omi {

/******************************************************************************\
| Abstract class that defines any component that can be rendered via Omicron's |
| renderer.                                                                    |
\******************************************************************************/
class Renderable : public Component {
public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //! is true if this component will be rendered
    bool visible;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Super constructor
    @param id the identifier of the component */
    Renderable(const std::string& id)
        :
        Component(id),
        visible (true) {
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Renderable() {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual component::Type getType() const {

        return component::RENDERABLE;
    }

protected:

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Render this component */
    virtual void render() = 0;
};

} // namespace omi

#endif

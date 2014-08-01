#ifndef OMICRON_ENTITY_COMPONENT_RENDERABLE_RENDERABLE_H_
#   define OMICRON_ENTITY_COMPONENT_RENDERABLE_RENDERABLE_H_

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

    /** Super constructor */
    Renderable()
        :
        visible (true) {
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Renderable();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

protected:

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Render this component */
    virtual void render() = 0;
};

} // namespace omi

#endif

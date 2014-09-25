#ifndef VOIDWALKER_SHIP_RANDOMSTILLDRAWCOMP_HPP_
#   define VOIDWALKER_SHIP_RANDOMSTILLDRAWCOMP_HPP_

#include "DrawComponent.hpp"

/*****************************************************************************\
| A block draw component that shows a static sprite but uses an animation and |
| randomly selects a single frame to use.                                     |
\*****************************************************************************/
class RandomStillDrawComp : public DrawComponent {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new random still draw component
    @param renderableName the name of the renderable to use for the component */
    RandomStillDrawComp( const std::string& renderableName );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    omi::Component* getComponent( omi::Transform* transform );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the name of the renderable to use
    std::string m_renderableName;
};

#endif

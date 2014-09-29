#ifndef VOIDWALKER_SHIP_BUILDERCOMPONENT_HPP_
#   define VOIDWALKER_SHIP_BUILDERCOMPONENT_HPP_

#include "src/omicron/entity/Entity.hpp"

class BuilderComponent {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new builder component
    @param renderables a list of the renderable components of the block */
    BuilderComponent( const std::vector<omi::Renderable*>& renderables );

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~BuilderComponent();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Updates the builder component */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the list of renderables used by the block
    std::vector<omi::Renderable*> m_renerables;

    // is true if the block is selected
    bool m_selected;
};

#endif

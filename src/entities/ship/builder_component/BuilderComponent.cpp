#include "BuilderComponent.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BuilderComponent::BuilderComponent(
        const std::vector<omi::Renderable*>& renderables )
    :
    m_renerables( renderables )
{
    // set the renderables to be selectable
    for (std::vector<omi::Renderable*>::iterator it = m_renerables.begin();
         it != m_renerables.end(); ++it )
    {
        ( *it )->selectable = true;
    }
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

BuilderComponent::~BuilderComponent()
{
    // set the renderable components to not be selectable
    for (std::vector<omi::Renderable*>::iterator it = m_renerables.begin();
         it != m_renerables.end(); ++it )
    {
        ( *it )->selectable = false;
    }
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderComponent::update()
{

}

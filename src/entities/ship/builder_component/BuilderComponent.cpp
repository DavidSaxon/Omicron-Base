#include "BuilderComponent.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BuilderComponent::BuilderComponent(
        const std::vector<omi::Renderable*>& renderables )
    :
    m_renerables( renderables ),
    m_selected  ( false )
{
    // TODO: this should potentially disable all other renderables other than
    // the first one
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
    if ( omi::input::mousePressed( omi::input::mouse_button::LEFT ) )
    {
        // check if any other renderables are selected
        m_selected = false;
        for (std::vector<omi::Renderable*>::iterator it = m_renerables.begin();
             it != m_renerables.end(); ++it )
        {
            if ( ( *it )->selected )
            {
                m_selected = true;
            }
        }
    }

    for (std::vector<omi::Renderable*>::iterator it = m_renerables.begin();
         it != m_renerables.end(); ++it )
    {
        if ( m_selected )
        {
            ( *it )->getMaterial().colour = glm::vec4( 1.0f, 0.0f, 0.0f, 1.0f );
        }
        else
        {
            ( *it )->getMaterial().colour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
        }
    }
}

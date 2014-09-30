#include "BuilderComponent.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BuilderComponent::BuilderComponent(
              omi::Transform*                transform,
        const std::vector<omi::Renderable*>& renderables )
    :
    m_transform ( transform ),
    m_renerables( renderables ),
    m_mouseDown ( false ),
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
    selection();
    move();

    // TODO: remove this
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

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderComponent::selection()
{
    if ( omi::input::mousePressed( omi::input::mouse_button::LEFT ) &&
         !m_selected && !m_mouseDown)
    {
        m_mouseDown = true;
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
        // calculate the selection offset if this has been selected
        if ( m_selected )
        {
            // get the mouse in world space
            glm::vec3 mousePos =
                omi::util::screenToWorld2D( omi::input::getMousePos() );
            m_selectOffset = mousePos - m_transform->translation;
        }
    }
    else if ( !omi::input::mousePressed( omi::input::mouse_button::LEFT ) )
    {
        m_mouseDown = false;
        m_selected = false;
    }
}

void BuilderComponent::move()
{
    // don't do anything if the block is not selected
    if ( ! m_selected)
    {
        return;
    }

    // get the mouse co-ordinates in world space
    glm::vec3 mousePos =
        omi::util::screenToWorld2D( omi::input::getMousePos() );
    // apply to the position of the block
    m_transform->translation = mousePos - m_selectOffset;
}

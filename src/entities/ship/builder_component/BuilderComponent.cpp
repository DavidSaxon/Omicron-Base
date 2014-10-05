#include "BuilderComponent.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BuilderComponent::BuilderComponent(
              omi::Transform*                transform,
        const std::vector<omi::Renderable*>& renderables )
    :
    m_transform ( transform ),
    m_renderables( renderables ),
    m_mouseDown ( false ),
    m_selected  ( false )
{
    // TODO: this should potentially disable all other renderables other than
    // the first one
    // set the renderables to be selectable and store their original layers
    for (std::vector<omi::Renderable*>::iterator it = m_renderables.begin();
         it != m_renderables.end(); ++it )
    {
        ( *it )->selectable = true;
        m_layers.push_back( ( *it )->getLayer() );
    }
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

BuilderComponent::~BuilderComponent()
{
    // set the renderable components to not be selectable
    for (std::vector<omi::Renderable*>::iterator it = m_renderables.begin();
         it != m_renderables.end(); ++it )
    {
        ( *it )->selectable = false;
    }
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderComponent::init( omi::Entity* owner )
{
    // create the collision detector
    m_detector = new omi::CollisionDetector(
            "", "builder_block", owner );
    m_detector->addBounding(
            new omi::BoundingCircle( 0.55f, m_transform ) );
}

void BuilderComponent::update()
{
    selection();
    move();
}

omi::CollisionDetector* BuilderComponent::getCollisionDetector()
{
    return m_detector;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderComponent::selection()
{
    // the mouse has been pressed
    if ( omi::input::mousePressed( omi::input::mouse_button::LEFT ) &&
         !m_mouseDown)
    {
        m_mouseDown = true;
        // check if any other renderables are selected
        m_selected = false;
        for (std::vector<omi::Renderable*>::iterator it = m_renderables.begin();
             it != m_renderables.end(); ++it )
        {
            if ( ( *it )->selected )
            {
                m_selected = true;
                BlockSelect::setVisibility( true );
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
    // the mouse has been released
    else if ( !omi::input::mousePressed( omi::input::mouse_button::LEFT ) )
    {
        m_mouseDown = false;
        if ( m_selected )
        {
            // revert selection and hide selector
            m_selected = false;
            BlockSelect::setVisibility( false );
        }
    }

    // update the layer of the renderables
    for ( unsigned i = 0; i < m_renderables.size(); ++i )
    {
        if ( m_selected )
        {
            m_renderables[i]->setLayer( layer::BUILDER_SELECT );
        }
        else
        {
            m_renderables[i]->setLayer( m_layers[i] );
        }
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
    // apply to the position of the block and selector
    m_transform->translation = mousePos - m_selectOffset;
    BlockSelect::setPosition( m_transform->translation );
}

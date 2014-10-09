#include "BuilderComponent.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BuilderComponent::BuilderComponent(
              omi::Transform*                transform,
              ConnectionComponent*           connection,
        const std::vector<omi::Renderable*>& renderables )
    :
    m_transform  ( transform ),
    m_connection ( connection ),
    m_renderables( renderables ),
    m_mouseDown  ( false ),
    m_selected   ( false ),
    m_released   ( false )
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
    if ( m_selected )
    {
        move();
        snap();
    }
    else if ( m_released )
    {
        release();
        m_released = false;
    }
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
                omi::transutil::screenToWorld2D( omi::input::getMousePos() );
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
            m_released = true;
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
    // get the mouse co-ordinates in world space
    glm::vec3 mousePos =
        omi::transutil::screenToWorld2D( omi::input::getMousePos() );
    // apply to the position of the block and selector
    m_transform->translation = mousePos - m_selectOffset;
    BlockSelect::setPosition( m_transform->translation );
}

void BuilderComponent::snap()
{
    // find the closest block this colliding with that has free space
    Block* nearest = NULL;
    float distance = 1000000.0f;
    connection::Direction direction = connection::TOP;
    for ( std::vector<omi::CollisionData>::iterator data =
          m_detector->getCollisionData().begin();
          data != m_detector->getCollisionData().end(); ++data )
    {
        // cast as a block
        Block* block = static_cast<Block*>( data->entity );
        // get the side of the block we are closet to and check if we can
        // connect
        float dir = omi::vecutil::angleBetween(
            m_transform->translation.xy, block->getPos().xy
        );
        if ( dir >= 315.0f || dir < 45.0f )
        {
            if ( !block->connectionComponent->isAvailable( connection::RIGHT )
                            || !m_connection->isAvailable( connection::LEFT ) )
            {
                continue;
            }
            direction = connection::RIGHT;
        }
        else if ( dir >= 45.0f && dir < 135.0f )
        {
            if ( !block->connectionComponent->isAvailable( connection::TOP )
                           || !m_connection->isAvailable( connection::BOTTOM ) )
            {
                continue;
            }
            direction = connection::TOP;
        }
        else if ( dir >= 135.0f && dir < 225.0f )
        {
            if ( !block->connectionComponent->isAvailable( connection::LEFT )
                            || !m_connection->isAvailable( connection::RIGHT ) )
            {
                continue;
            }
            direction = connection::LEFT;
        }
        else
        {
            if ( !block->connectionComponent->isAvailable( connection::BOTTOM )
                            || !m_connection->isAvailable( connection::TOP ) )
            {
                continue;
            }
            direction = connection::BOTTOM;
        }
        // check if we can connect to the closet edge of the block
        // get distance
        float dis = glm::distance( m_transform->translation, block->getPos() );
        // check if this is the nearest block
        if ( dis < distance )
        {
            nearest = block;
        }
    }

    // snap to the block
    if ( nearest != NULL )
    {
        std::cout << direction << std::endl;
        glm::vec3 pos = nearest->getPos() + connection::vecFromDir( direction );
        BlockSelect::setPosition( pos );
        setRenderableTransform( new omi::Transform(
            "", pos,
            m_transform->rotation,
            m_transform->scale
        ) );
    }
    else
    {
        setRenderableTransform( m_transform );
    }
}

void BuilderComponent::release()
{
    // TODO: if snapped
    // place the block onto the nearest grid cell
    glm::vec3 pos = m_transform->translation;
    float xDec = pos.x - int( pos.x );
    if ( xDec <= 0.5f )
    {
        pos.x -= xDec;
    }
    else
    {
        pos.x += 1.0f - xDec;
    }
    float yDec = pos.y - int( pos.y );
    if ( yDec <= 0.5f )
    {
        pos.y -= yDec;
    }
    else
    {
        pos.y += 1.0f - yDec;
    }
    m_transform->translation = pos;
    setRenderableTransform( m_transform );
}

void BuilderComponent::setRenderableTransform( omi::Transform* transform )
{
    for (std::vector<omi::Renderable*>::iterator it = m_renderables.begin();
         it != m_renderables.end(); ++it )
    {
        ( *it )->setTransform( transform );
    }
}

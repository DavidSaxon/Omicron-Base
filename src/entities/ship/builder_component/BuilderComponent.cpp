#include "BuilderComponent.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BuilderComponent::BuilderComponent( BuilderGrid* grid )
    :
    m_owner      ( NULL ),
    m_grid       ( grid ),
    m_transform  ( NULL ),
    m_connection ( NULL ),
    m_mouseDown  ( false ),
    m_selected   ( false ),
    m_released   ( false )
{
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

void BuilderComponent::init(
          omi::Entity*                   owner,
          omi::Transform*                transform,
          ConnectionComponent*           connection,
    const std::vector<omi::Renderable*>& renderables )
{
    // set variables
    m_owner       = static_cast<Block*>(owner);
    m_transform   = transform;
    m_connection  = connection;
    m_renderables = renderables;

    // place into the grid
    m_grid->set(
        m_transform->translation.x,
        m_transform->translation.y,
        m_owner
    );

    // TODO: this should potentially disable all other renderables other than
    // the first one
    // set the renderables to be selectable and store their original layers
    for (std::vector<omi::Renderable*>::iterator it = m_renderables.begin();
         it != m_renderables.end(); ++it )
    {
        ( *it )->selectable = true;
        m_layers.push_back( ( *it )->getLayer() );
    }

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
                m_preSelectPos = m_transform->translation;
                BlockSelect::setVisibility( true );
                BlockSelect::setValidColour();
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
    // check which connection's are available
    glm::vec3 gridPos = m_transform->translation;
    // top connection
    BlockSelect::setTopVisibility( false );
    Block* top = m_grid->get( gridPos.x, gridPos.y, connection::TOP );
    if ( top != NULL && top != m_owner )
    {
        if ( top->connectionComponent->isAvailable( connection::BOTTOM ) &&
             m_connection->isAvailable( connection::TOP ) )
        {
            BlockSelect::setTopVisibility( true );
        }
    }
    // bottom connection
    BlockSelect::setBottomVisibility( false );
    Block* bottom = m_grid->get( gridPos.x, gridPos.y, connection::BOTTOM );
    if ( bottom != NULL && bottom != m_owner )
    {
        if ( bottom->connectionComponent->isAvailable( connection::TOP ) &&
             m_connection->isAvailable( connection::BOTTOM ) )
        {
            BlockSelect::setBottomVisibility( true );
        }
    }
    // left connection
    BlockSelect::setLeftVisibility( false );
    Block* left = m_grid->get( gridPos.x, gridPos.y, connection::LEFT );
    if ( left != NULL && left != m_owner )
    {
        if ( left->connectionComponent->isAvailable( connection::RIGHT ) &&
             m_connection->isAvailable( connection::LEFT ) )
        {
            BlockSelect::setLeftVisibility( true );
        }
    }
    // right connection
    BlockSelect::setRightVisibility( false );
    Block* right = m_grid->get( gridPos.x, gridPos.y, connection::RIGHT );
    if ( right != NULL && right != m_owner )
    {
        if ( right->connectionComponent->isAvailable( connection::LEFT ) &&
             m_connection->isAvailable( connection::RIGHT ) )
        {
            BlockSelect::setRightVisibility( true );
        }
    }
    // check if the position is valid
    if ( m_grid->get( gridPos.x, gridPos.y ) != NULL &&
         m_grid->get( gridPos.x, gridPos.y ) != m_owner )
    {
        BlockSelect::setInvalidColour();
        BlockSelect::setTopVisibility( false );
        BlockSelect::setBottomVisibility( false );
        BlockSelect::setLeftVisibility( false );
        BlockSelect::setRightVisibility( false );
    }
    else
    {
        BlockSelect::setValidColour();
    }
    // get the block position on the grid and set the selector position to it
    gridPos.x = util::math::round( gridPos.x );
    gridPos.y = util::math::round( gridPos.y );
    BlockSelect::setPosition( gridPos );

}

void BuilderComponent::release()
{
    glm::vec3 pos = m_transform->translation;
    // check that the nearest grid cell is empty
    if ( m_grid->get( pos.x, pos.y ) == NULL )
    {
        // TODO: needs a special case if this is a new block
        // remove this block from the grid
        m_grid->set( m_preSelectPos.x, m_preSelectPos.y, NULL );
        // place the block onto the nearest grid cell and update it's position to
        // match
        m_grid->set( pos.x, pos.y, m_owner );
        pos.x = util::math::round( pos.x );
        pos.y = util::math::round( pos.y );
        m_transform->translation = pos;
        setRenderableTransform( m_transform );
    }
    else
    {
        // TODO: needs a special case if this is a new block
        // send the piece back to it's original position
        m_grid->set( m_preSelectPos.x, m_preSelectPos.y, m_owner );
        glm::vec3 pos = m_transform->translation = m_preSelectPos;
    }
}

void BuilderComponent::setRenderableTransform( omi::Transform* transform )
{
    for (std::vector<omi::Renderable*>::iterator it = m_renderables.begin();
         it != m_renderables.end(); ++it )
    {
        ( *it )->setTransform( transform );
    }
}

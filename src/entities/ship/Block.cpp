#include "Block.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Block::Block(const glm::vec3& pos ) :
    drawComponent( NULL )
{
    // set up the initial transform using the given position
    m_transform = new omi::Transform(
        "", pos,
        glm::vec3(),
        glm::vec3( 1.0f, 1.0f, 1.0f )
    );
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Block::~Block()
{
    // delete existing components
    delete drawComponent;
    drawComponent = NULL;
    delete builderComponent;
    builderComponent = NULL;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Block::init()
{
    // add the transform component
    m_components.add( m_transform );

    // get components from ship components
    if ( drawComponent )
    {
        drawComponent->init( m_transform );
        for ( std::vector<omi::Renderable*>::const_iterator it =
              drawComponent->getRenderables().begin();
              it != drawComponent->getRenderables().end(); ++it )
        {
            m_components.add( *it );
        }

    }

    // TODO: this component should be created depending on mode
    builderComponent = new BuilderComponent(
        m_transform,
        drawComponent->getRenderables()
    );
    builderComponent->init( this );
    m_detector = builderComponent->getCollisionDetector();
    m_components.add( m_detector );
}

void Block::update()
{
    builderComponent->update();
}

const glm::vec3& Block::getPos() const
{
    return m_transform->translation;
}

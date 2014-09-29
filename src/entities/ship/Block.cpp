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
    builderComponent = new BuilderComponent( drawComponent->getRenderables() );
}

void Block::update()
{
}

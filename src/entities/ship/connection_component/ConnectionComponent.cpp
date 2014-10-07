#include "ConnectionComponent.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

ConnectionComponent::ConnectionComponent( unsigned directions )
    :
    m_directions( directions ),
    m_top       ( NULL ),
    m_bottom    ( NULL ),
    m_left      ( NULL ),
    m_right     ( NULL ),
    m_above     ( NULL )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

unsigned ConnectionComponent::getDirections() const
{
    return m_directions;
}

bool ConnectionComponent::isAvailable( connection::Direction direction )
{
    // check if the direction is allowed
    if ( static_cast<unsigned>( m_directions & direction ) == 0 )
    {
        return false;
    }
    // check if the direction has a block
    if ( getBlock( direction ) != NULL )
    {
        return false;
    }
    // available
    return true;
}

Block* ConnectionComponent::getBlock( connection::Direction direction )
{
    switch ( direction )
    {
        case connection::TOP:
        {
            return m_top;
        }
        case connection::BOTTOM:
        {
            return m_bottom;
        }
        case connection::LEFT:
        {
            return m_left;
        }
        case connection::RIGHT:
        {
            return m_right;
        }
        case connection::ABOVE:
        {
            return m_above;
        }
    }
    return NULL;
}

void ConnectionComponent::connect(
        connection::Direction direction, Block* block )
{
    // TODO: check if connection is valid
    switch ( direction )
    {
        case connection::TOP:
        {
            m_top = block;
            break;
        }
        case connection::BOTTOM:
        {
            m_bottom = block;
            break;
        }
        case connection::LEFT:
        {
            m_left = block;
            break;
        }
        case connection::RIGHT:
        {
            m_right = block;
            break;
        }
        case connection::ABOVE:
        {
            m_above = block;
            break;
        }
    }
}

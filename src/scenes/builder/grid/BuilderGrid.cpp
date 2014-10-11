#include "BuilderGrid.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BuilderGrid::BuilderGrid()
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

Block* BuilderGrid::get( float x, float y )
{
    // get the key for this position
    std::string key = posToKey( x, y );
    // make sure the key exists
    if ( m_grid.find( key ) == m_grid.end() )
    {
        // there is nothing at this position
        return NULL;
    }
    // return the block at the position
    return m_grid[key];
}

// TODO: positions need to be able to contain multiple blocks ( do as extension)
void BuilderGrid::set( float x, float y, Block* block )
{
    // get the key for this position
    std::string key = posToKey( x, y );
    // if the position doesn't exists, create it
    if ( m_grid.find( key ) == m_grid.end() )
    {
        m_grid.insert( std::make_pair( key, block ) );
    }
    // overwrite what is current at the position
    else
    {
        m_grid[key] = block;
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

std::string BuilderGrid::posToKey( float x, float y ) const
{
    // round the values fists
    x = util::math::round( x );
    y = util::math::round( y );
    // convert to string
    std::stringstream ss;
    ss << x << "_" << y;
    return ss.str();
}

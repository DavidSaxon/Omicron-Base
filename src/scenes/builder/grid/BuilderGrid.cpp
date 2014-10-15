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

Block* BuilderGrid::get( float x, float y, connection::Direction direction )
{
    glm::vec3 vec = connection::vecFromDir( direction );
    x += vec.x;
    y += vec.y;
    return get( x, y );
}

void BuilderGrid::getSize( float& minX, float& maxX, float& minY, float& maxY )
{
    // search over the map for
    bool first = true;
    for ( std::map<std::string, Block*>::iterator it = m_grid.begin();
          it != m_grid.end(); ++it )
    {
        // ignore if there is no block here
        if ( it->second == NULL )
        {
            continue;
        }
        // get the position of each item
        float x = 0.0f;
        float y = 0.0f;
        keyToPos( it->first, x, y );
        // store the first element (in case it's the only block)
        if ( first )
        {
            minX = x;
            maxX = x;
            minY = y;
            maxY = y;
            first = false;
        }
        else
        {
            // store if smaller than the current value
            if ( x < minX )
            {
                minX = x;
            }
            if ( x > maxX )
            {
                maxX = x;
            }
            if ( y < minY )
            {
                minY = y;
            }
            if ( y > maxY )
            {
                maxY = y;
            }
        }
    }
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

void BuilderGrid::keyToPos( const std::string& key, float& x, float& y )
{
    // split at the underscore
    unsigned mid = key.find_last_of( "_" );
    x = static_cast<float>( atof( key.substr( 0, mid ).c_str() ) );
    y = static_cast<float>(
        atof( key.substr( mid + 1, key.length() ).c_str() ) );
}

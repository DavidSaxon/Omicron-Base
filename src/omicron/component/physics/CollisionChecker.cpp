#include "CollisionChecker.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

CollisionChecker::CollisionChecker( const std::string& id ) :
    Physics( id )
{
}

CollisionChecker::CollisionChecker(
        const std::string& id,
        const std::vector<BoundingShape*>& boundings )
    :
    Physics( id ),
    m_boundings( boundings )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

const std::vector<BoundingShape*> CollisionChecker::getBoundings() const
{
    return m_boundings;
}

void CollisionChecker::addBounding( BoundingShape* bounding )
{
    m_boundings.push_back( bounding );
}

} // namespace omi

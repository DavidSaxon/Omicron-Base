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

bool CollisionChecker::forwardCheck(
        const glm::vec3& move,
        const std::string& group )
{
    bool collision = false;
    // check each bounding
    for ( std::vector<BoundingShape*>::iterator it = m_boundings.begin();
          it != m_boundings.end(); ++it )
    {
        BoundingShape* bounding = *it;

        // change the position of the transform of the bounding
        glm::vec3 orginalPos = bounding->getTransform()->translation;
        glm::vec3 newPos = orginalPos + move;
        bounding->getTransform()->translation = newPos;

        if ( !CollisionDetect::checkAgainstGroup( bounding, group ).empty() )
        {
            collision = true;
            // reset position
            bounding->getTransform()->translation = orginalPos;
            break;
        }

        // reset position
        bounding->getTransform()->translation = orginalPos;
    }

    return collision;
}

} // namespace omi

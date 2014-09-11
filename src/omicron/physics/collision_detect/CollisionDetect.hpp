#ifndef OMICRON_PHYSICS_COLLISION_DETECT_COLLISIONDETECT_H_
#   define OMICRON_PHYSICS_COLLISION_DETECT_COLLISIONDETECT_H_

#include <map>
#include <vector>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/component/physics/CollisionDetector.hpp"
#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/physics/bounding/BoundingCircle.hpp"

namespace omi {

struct CheckPair {
    std::string a;
    std::string b;
};

/**************************************************\
| Used for detecting collisions between boundings. |
\**************************************************/
class CollisionDetect {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_CONSTRUCTION(CollisionDetect);

public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Sets a collision group to be check against a second collision group
    @param a the first group to check
    @param b the second group to check against*/
    static void checkGroup(const std::string& a, const std::string& b);

    // TODO: remove groups check

    /** #Hidden
    Performs collision group detection for a frame */
    static void update();

    /** @param detector new collision detector to add */
    static void addDetector(CollisionDetector* detector);

    /** @param detector collision detector to remove */
    static void removeDetector(CollisionDetector* detector);

    /** Clears all bounding groups  */
    static void clear();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the groups and their detectors
    static std::map<std::string, CollisionDetector*> m_groups;
    // groups to check
    static std::vector<CheckPair> m_check;
};

} // namespace omi

#endif
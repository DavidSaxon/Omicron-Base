#include "CollisionDetect.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

std::map<std::string, CollisionDetector*> CollisionDetect::m_groups;
std::vector<CheckPair> CollisionDetect::m_check;

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CollisionDetect::checkGroup(const std::string& a, const std::string& b) {

    // TODO: check pair doesn't already exists
    CheckPair pair;
    pair.a = a;
    pair.b = b;
    m_check.push_back(pair);
}

void CollisionDetect::update() {

    // TODO: collision detection here
}

void CollisionDetect::addDetector(CollisionDetector* detector) {

    m_groups.insert(std::make_pair(detector->getGroup(), detector));
}

void CollisionDetect::removeDetector(CollisionDetector* detector) {

    // TODO:
}

void CollisionDetect::clear() {

    m_check.clear();
}

} // namespace omi
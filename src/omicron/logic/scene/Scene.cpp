#include "Scene.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool Scene::execute() {

    //update all the entities
    updateEntities();
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Scene::addEntity(Entity* entity) {

    m_entities.push_back(entityPtr(entity));
}

bool Scene::removeEntity(Entity* entity) {

    //TODO: implement
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Scene::updateEntities() {


}

} //namespace omi

#include "Scene.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool Scene::execute() {

    //update all the entities
    updateEntities();

    //update this scene
    return update();
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Scene::addEntity(Entity* entity) {

    m_entities.push_back(EntityPtr(entity));
}

bool Scene::removeEntity(Entity* entity) {

    //TODO: implement
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Scene::updateEntities() {

    for (EntityList::iterator it = m_entities.begin();
         it != m_entities.end(); ++it) {

        (*it)->update();
    }
}

} //namespace omi

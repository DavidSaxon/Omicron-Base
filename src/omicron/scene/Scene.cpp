#include "Scene.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool Scene::execute() {

    // update this scene and store whether it's complete
    bool complete = update();

    // update all the entities
    updateEntities();

    // find all dirty components
    findDirty();

    return complete;
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Scene::addEntity(Entity* entity) {

    m_entities.push_back(t_EntityPtr(entity));
}

bool Scene::removeEntity(Entity* entity) {

    // TODO: implement
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Scene::updateEntities() {

    for (t_EntityList::iterator it = m_entities.begin();
         it != m_entities.end(); ++it) {

        (*it)->update();
    }
}

void Scene::findDirty() {

    for (t_EntityList::iterator it = m_entities.begin();
         it != m_entities.end(); ++it) {

        for (std::vector<Component*>::iterator itc =
            (*it)->getComponents().dirty.begin();
            itc != (*it)->getComponents().dirty.end(); ++itc) {

            dirtyComponents.insert(*itc);
        }

        // clear the dirty components on the entity
        (*it)->getComponents().dirty.clear();
    }
}

} // namespace omi

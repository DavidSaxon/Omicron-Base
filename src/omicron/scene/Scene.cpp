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

    // initialise the entity
    entity->init();

    // TODO: check that the entity doesn't already exists in the scene

    // add to the list of all entities in the scene
    m_entities.push_back(t_EntityPtr(entity));
}

bool Scene::removeEntity(Entity* entity) {

    // TODO: should this exists?? (probably)
    // TODO: implement
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Scene::updateEntities() {

    // find all the new entities
    std::vector<Entity*> newEntities;
    for (t_EntityList::iterator it = m_entities.begin();
         it != m_entities.end(); ++it) {

        for (std::vector<Entity*>::iterator itn = (*it)->getAddList().begin();
             itn != (*it)->getAddList().end(); ++itn) {

            newEntities.push_back(*itn);
        }

        // clear the entities new entities
        (*it)->getAddList().clear();
    }

    // copy the new entities into the list of all entities and initialise them
    for (std::vector<Entity*>::iterator it = newEntities.begin();
         it != newEntities.end(); ++it) {

        (*it)->init();
        m_entities.push_back(t_EntityPtr(*it));
    }

    // iterate over all the existing entities in the scene and update them
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

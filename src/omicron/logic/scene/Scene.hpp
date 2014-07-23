#ifndef OMICRON_LOGIC_SCENE_SCENE_H_
#   define OMICRON_LOGIC_SCENE_SCENE_H_

#include <memory>
#include <vector>

#include "src/omicron/logic/entity/Entity.hpp"

namespace omi {

//-----------------------------------TYPEDEFS-----------------------------------

typedef std::unique_ptr<Entity> EntityPtr;
typedef std::vector<EntityPtr>  EntityList;

/*********************************************\
| Abstract base class that all scenes extend. |
\*********************************************/
class Scene {
public:

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~Scene() {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**#Hidden
    Controls execution of the scene*/
    bool execute();

    /**performs a logic cycle of the scene
    @return if true the scene is complete and next scene should begin*/
    virtual bool update() = 0;

    /**@return the next scene to be executed*/
    virtual Scene* nextScene() const = 0;

    //TODO: input

protected:

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Adds a new entity
    #NOTE: the scene will hold ownership of the entity pointer
    @param entity the new entity to add*/
    void addEntity(Entity* entity);

    /**Removes an entity if it exists within the scene
    #NOTE: the pointer to the entity will be deleted
    @param entity the entity to remove
    @return whether or not the entity existed within the scene and was
    therefore removed*/
    bool removeEntity(Entity* entity);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //the list of entities
    EntityList m_entities;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Updates all entities in the entity list*/
    void updateEntities();

};

} //namespace omi

#endif

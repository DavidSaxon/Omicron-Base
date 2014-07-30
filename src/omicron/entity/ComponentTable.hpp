#ifndef OMICRON_ENTITY_COMPONENTTABLE_H_
#   define OMICRON_ENTITY_COMPONENTTABLE_H_

#include "lib/Utilitron/MacroUtil.hpp"

#include <map>
#include <memory>
#include <string>

#include "src/omicron/entity/component/Component.hpp"
#include "src/omicron/entity/component/Transform.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                    TYPEDEF
//------------------------------------------------------------------------------

typedef std::map<std::string, std::unique_ptr<Component>> ComponentMap;

class ComponentTable {

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(ComponentTable);

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Create a new Component Table*/
    ComponentTable();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~ComponentTable();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**@Get the component with the given type and id if it exists within the
    table. If it doesn't a null pointer will be returned
    @param id the identifier of the component to get
    @return the component if it was found else null*/
    template<typename T>
    T* getCompontent(const std::string& id);

    /**Adds a component to the table
    #NOTE: the component table will take ownership of the component pointer
    @param component the pointer to the component*/
    void addComponent(Component* component);

    /**Removes the component with the given id from the able
    @param id the identifier of the component to remove
    @return if a component was successfully removed from the table*/
    bool removeComponent(const std::string& id)

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //the map from component ids to components
    ComponentMap m_components;
};

} //namespace omi

#endif
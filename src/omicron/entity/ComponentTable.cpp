#include "ComponentTable.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

ComponentTable::ComponentTable() {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

ComponentTable::~ComponentTable() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool ComponentTable::contains(const std::string& id) {

    //search for the key in the table
    ComponentMap::iterator it = m_components.find(id);
    return it != m_components.end();
}

Component* ComponentTable::get(const std::string& id) {

    //check if the id is contained within the table
    if (contains(id)) {

        return m_components[id].get();
    }

    return NULL;
}

void ComponentTable::add(Component* component) {

    m_components.insert(std::make_pair(
        component->getId(), std::unique_ptr<Component>(component)));
}

bool ComponentTable::remove(const std::string& id) {

    //check if the id is contained within the table
    if (contains(id)) {

        m_components.erase(m_components.find(id));
        return true;
    }

    return false;
}

} //namespace omi
#include "BuilderEnvironment.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderEnvironment::init()
{
    initComponents();
}

void BuilderEnvironment::update()
{
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderEnvironment::initComponents()
{
    //----------------------------GENERIC TRANSFORMS----------------------------
    omi::Transform* m_zeroT = new omi::Transform(
        "",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_zeroT);
    //--------------------------------BACKGROUND--------------------------------
    m_components.add(omi::ResourceManager::getSprite(
        "builder_background", "", m_zeroT));
}
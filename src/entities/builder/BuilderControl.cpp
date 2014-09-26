#include "BuilderControl.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderControl::init()
{
    initComponents();
}

void BuilderControl::update()
{
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderControl::initComponents()
{
    //----------------------------------CAMERA----------------------------------
    m_camT = new omi::Transform(
        "",
        glm::vec3( 0.0f, 0.0f, -1.0f ),
        glm::vec3(),
        glm::vec3( 0.2f, 0.2f, 0.2f )
    );
    m_components.add( new omi::Camera("", omi::cam::ORTHOGRAPHIC, m_camT ) );
}

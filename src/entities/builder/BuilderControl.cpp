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
        util::vec::Vector3( 0.0f, 0.0f, -1.0f ),
        util::vec::Vector3(),
        util::vec::Vector3( 0.05f, 0.05f, 0.05f )
    );
    m_components.add( new omi::Camera("", omi::cam::ORTHOGRAPHIC, m_camT ) );
}

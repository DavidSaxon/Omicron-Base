#include "BuilderControl.hpp"

namespace {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

static const float ZOOM_SPEED = 0.1f;

} // namespace anonymous

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderControl::init()
{
    initComponents();
}

void BuilderControl::update()
{
    zoom();
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BuilderControl::zoom()
{
    float zoom = m_camT->scale.x;
    zoom += static_cast<float>( omi::input::getMouseScroll() ) *
            ( ZOOM_SPEED * zoom );
    m_camT->scale = glm::vec3( zoom );
}

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

#include "Input.hpp"

namespace omi {

namespace input {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

glm::vec2 getMousePos()
{
    sf::Vector2i pos = sf::Mouse::getPosition();
    return glm::vec2(
        static_cast<float>( pos.x ),
        static_cast<float>( pos.y )
    );
}

bool mousePressed( mouse_button::Type button )
{
    return sf::Mouse::isButtonPressed( sf::Mouse::Button( button ) );
}

} // namespace input

} // namespace omi

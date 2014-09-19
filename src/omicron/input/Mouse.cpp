#include "Input.hpp"

namespace omi {
    
namespace input {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

util::vec::Vector2 getMousePos()
{
    sf::Vector2i pos = sf::Mouse::getPosition();
    return util::vec::Vector2( 
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
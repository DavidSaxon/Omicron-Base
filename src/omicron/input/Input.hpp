#ifndef OMICRON_INPUT_INPUT_H_
#   define OMICRON_INPUT_INPUT_H_

#include <ctype.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>

#include "lib/Utilitron/Vector.hpp"

namespace omi {

/*********************************\
| functions handling input events |
\*********************************/
namespace input {

//------------------------------------------------------------------------------
//                                  ENUMERATORS
//------------------------------------------------------------------------------

// mouse button types
enum MouseButton {

    LEFT,
    MIDDLE,
    RIGHT
};

//------------------------------------------------------------------------------
//                                   PROTOTYPES
//------------------------------------------------------------------------------

//------------------------------------MOUSE-------------------------------------

/** #Hidden
Is called when the mouse is moved */
void mouseMove(int x, int y);

/** #Hidden
Is called when a mouse button is pressed */
void mouseButton(int button, int state, int x, int y);

/** #Hidden
switch the mouse buffers */
void switchMouseBuffers();

/** @return the mouse position */
const util::vec::Vector2& getMousePos();

/** @return if the given mouse button is being pressed */
bool mousePressed(MouseButton button);

//-----------------------------------KEYBOARD-----------------------------------

/** #Hidden
Is called when a key is pressed */
void keyPressed(unsigned char key, int x, int y);

/** #Hidden
Is called when a key is released */
void keyReleased(unsigned char key, int x, int y);

/** #Hidden
Is called when a special key is pressed */
void specialPressed(int key, int x, int y);

/** #Hidden
Is called when a special key is released */
void specialReleased(int key, int x, int y);

/** Check if the given is being pressed
#NOTE: this does not take into consideration upper and lower case
@param key the character of the key to check for
@return if the key is being pressed*/
bool isKeyPressed(unsigned char key);

/** Check if a character is being prssed
@param key the character to check for
@return if the key is being pressed */
bool isCharPressed(unsigned char key);

/** Check if the given special key is pressed
@param key the glut enum of the special key to check for
@return if the key is being pressed */
bool isSpecialPressed(int key);

} // namespace input

} // namespace omi

#endif
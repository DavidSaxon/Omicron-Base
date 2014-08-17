#ifndef OMICRON_RENDERING_SHADING_ANIMATION_H_
#   define OMICRON_RENDERING_SHADING_ANIMATION_H_

#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>

#include "Texture.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                TYPE DEFINITIONS
//------------------------------------------------------------------------------

typedef std::vector<GLuint> t_TextureList;

/************************************************************************************\
| An animation is a subclass of a texture that can change the texture based on time. |
\************************************************************************************/
class Animation : public Texture {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates an empty animation */
    Animation();

    /** Creates a new animation with the given list of OpenGL texture pointers
    @param textures the list of pointers to OpenGL textures */
    Animation(const t_TextureList& textures);

    /** Creates a copy of the given animation
    @param other the animation to copy from */
    Animation(const Animation& other);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Animation();

    //--------------------------------------------------------------------------
    //                                 OPERATORS
    //--------------------------------------------------------------------------

    const Animation& operator=(const Animation& other);

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void update();

    /** #Override */
    tex::Type getType() const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the list of OpenGL pointers to textures
    t_TextureList m_textures;

    // the current frame of the animation
    unsigned m_frame;
};

} // namespace omi

#endif
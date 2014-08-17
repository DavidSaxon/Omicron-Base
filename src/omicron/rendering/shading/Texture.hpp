#ifndef OMICRON_RENDERING_SHADING_TEXTURE_H_
#   define OMICRON_RENDERING_SHADING_TEXTURE_H_

#include <GL/glew.h>
#include <GL/glut.h>

#include "lib/Utilitron/Vector.hpp"

namespace omi {

namespace tex {

    // the types of textures
    enum Type {

        TEXTURE,
        ANIMATION
    };
}

/*********************************************\
| A wrapper around an OpenGL texture pointer. |
\*********************************************/
class Texture {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a blank texture */
    Texture();

    /** Creates a new texture with the given OpenGL texture pointer
    @param id the pointer to the OpenGL texture*/
    Texture(GLuint id);

    /** Creates a copy of the given texture
    @param other the other texture from */
    Texture(const Texture& other);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Texture();

    //--------------------------------------------------------------------------
    //                                 OPERATORS
    //--------------------------------------------------------------------------

    const Texture& operator=(const Texture& other);

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Updates the texture */
    virtual void update();

    /** @return the OpenGL pointer to the current texture */
    GLuint getId() const;

    /** @return the type of the texture */
    virtual tex::Type getType() const;

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the OpenGL pointer to the texture
    GLuint m_id;
};

} // namespace omi

#endif
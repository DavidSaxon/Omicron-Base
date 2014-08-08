#ifndef OMICRON_RENDERING_SHADING_TEXTURE_H_
#   define OMICRON_RENDERING_SHADING_TEXTURE_H_

#include <GL/glut.h>

#include "lib/Utilitron/Vector.hpp"

namespace omi {

/*********************************************\
| A wrapper around an OpenGL texture pointer. |
\*********************************************/
class Texture {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates an empty texture */
    Texture();

    /** Creates a new texture with the given OpenGL texture pointer and data
    @param id the pointer to the OpenGL texture
    @param format the colour the format of the texture
    @param dimensions the dimesions of the texture in pixels
    @param alpha is true if the texture has an alpha component*/
    Texture(      GLuint              id,
                  int                 format,
            const util::vec::Vector2& dimensions,
                  bool                alpha);

    /** Creates a copy of the given texture
    @param other the texture to copy */
    Texture(const Texture& other);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Texture();

    //--------------------------------------------------------------------------
    //                                 OPERATORS
    //--------------------------------------------------------------------------

    /** Copies the values of the texture to this texture
    @param other the texture to copy from */
    const Texture& operator=(const Texture& other);

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** @return the OpenGL pointer to the texture */
    GLuint getId() const;

    /** @return the format of the texture */
    int getFormat() const;

    /** @return the dimensions of the texture in pixels */
    const util::vec::Vector2& getDimesions() const;

    /** @return whether the texture has an alpha component */
    bool hasAlpha() const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the OpenGL pointer to the texture
    GLuint m_id;
    // the format of the texture
    int m_format;
    // the dimensions of the texture
    util::vec::Vector2 m_dimensions;
    // is true if the texture has an alpha component
    bool m_alpha;
};

} // namespace omi

#endif
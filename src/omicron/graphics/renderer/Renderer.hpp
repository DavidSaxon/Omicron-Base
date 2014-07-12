#ifndef OMICRON_GRAPHICS_RENDERER_RENDERER_H_
#   define OMICRON_GRAPHICS_RENDERER_RENDERER_H_

#include <GL/glut.h>

#include "lib/Utilitron/MacroUtil.hpp"

class RenderSettings;

#include "src/omicron/Omicron.hpp"

namespace omi {

/****************************************************************************\
| The hub class controlling all rendering in Omicron. Rendering is performed |
| using OpenGL.                                                              |
\****************************************************************************/
class Renderer {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(Renderer);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /**Creates a new renderer*/
    Renderer();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Renderer();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Performs one frame of rendering*/
    void render();

private:

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /**Applies settings*/
    void applySettings();

    /**Initialises the renderer*/
    void init();
};

} //namespace

#endif
#ifndef OMICRON_RENDERING_RENDERER_H_
#   define OMICRON_RENDERING_RENDERER_H_

#include <GL/glut.h>
#include <IL/il.h>
#include <memory>

#include "lib/Utilitron/MacroUtil.hpp"

class RenderSettings;

#include "src/omicron/Omicron.hpp"
#include "src/omicron/rendering/RenderLists.hpp"

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

    /** Creates a new renderer */
    Renderer();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Renderer();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Performs one frame of rendering */
    void render();

    /** Adds a renderable component to the render lists to be rendered */
    void addRenderable(Renderable* renderable);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the render lists containing all things to be rendered
    std::unique_ptr<RenderLists> m_renderLists;

    float m_rot;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Applies settings */
    void applySettings();

    /** Initialises the renderer */
    void init();
};

} // namespace omi

#endif

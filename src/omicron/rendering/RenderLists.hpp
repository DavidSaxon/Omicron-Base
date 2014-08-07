#ifndef OMICRON_ENTITY_RENDERING_RENDERLISTS_H_
#   define OMICRON_ENTITY_RENDERING_RENDERLISTS_H_

#include <map>
#include <set>

#include "lib/Utilitron/MacroUtil.hpp"

#include "src/omicron/component/renderable/Renderable.hpp"

namespace omi {

//-----------------------------------TYPEDEF------------------------------------

typedef std::map<int, std::set<Renderable*>> t_RenderableMap;

/*************************************************************************\
| A set of lists that contain all objects to be rendered by the renderer. |
\*************************************************************************/
class RenderLists {
private:

    //--------------------------------------------------------------------------
    //                                RESTRICTIONS
    //--------------------------------------------------------------------------

    DISALLOW_COPY_AND_ASSIGN(RenderLists);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new set of render lists */
    RenderLists();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RenderLists();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Renders all of the renderable components contained within the render
    lists */
    void render();

    /** Adds a renderable component to the render lists
    @param renderable the renderable to add */
    void addRenderable(Renderable* renderable);

    /** Removes a renderable from the render lists
    @param renderable the renderable to remove */
    void removeRenderable(Renderable* renderable);

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // all renderable components grouped by layer
    t_RenderableMap m_renderables;
};

} // namespace omi

#endif

#ifndef OMICRON_COMPONENT_RENDERABLE_SPRITE_H_
#   define OMICRON_COMPONENT_RENDERABLE_SPRITE_H_

#include "src/omicron/component/renderable/Renderable.hpp"

namespace omi {

/********************************************************\
| A flat quad that is essentially considered as geometry |
\********************************************************/
class Sprite : public Renderable {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new sprite
    @param id the identifier of the component
    @param layer the render layer of the sprite
    @param transform a pointer to a transform to use for the spirte's position
    @param material the the material to use for sprite
    @param size the size of the sprite*/
    Sprite(const std::string&        id,
                 int                 layer,
                 Transform*          transform,
                 Material            material,
           const util::vec::Vector2& size);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Sprite();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Hidden
    Render the mesh */
    void render();

    /** @return the size of the sprite */
    const util::vec::Vector2& getSize() const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the size of the sprite
    util::vec::Vector2 m_size;
    // short hand for half the size of the sprite (so we don't have to
    // calculate it every frame)
    util::vec::Vector2 m_half;
};

} // namespace omi

#endif

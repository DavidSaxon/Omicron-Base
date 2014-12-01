#ifndef OMICRON_COMPONENT_RENDERABLE_TEXT_HPP_
#   define OMICRON_COMPONENT_RENDERABLE_TEXT_HPP_

#include "src/omicron/component/renderable/Renderable.hpp"
#include "src/omicron/rendering/shading/Font.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------


/*******************************\
| Renders a string using a font |
\*******************************/
class Text : public Renderable {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates new text to be rendered
    @param id the identifier of the component
    @param layer the render layer of the text
    @param transform a pointer to a transform to use for the text's position
    @param material the material to use for the text
    @param font the font to use
    @param str the string to render
    @param size the size of the font in world space co-ordinates */
    Text(
            const std::string& id,
            int layer,
            Transform* transform,
            Material material,
            Font* font,
            const std::string& str,
            float size );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //---------------------------------GETTERS----------------------------------

    /** @return the font being used to render the text */
    Font* getFont() const;

    /** @return the string that is being rendered */
    const std::string& getString() const;

    /** @return the size of the font */
    float getSize() const;

    //---------------------------------SETTERS----------------------------------

    /** @param font the new font to use for rendering the text */
    void setFont( Font* font );

    /** @param str the new string to render */
    void setString( const std::string& str );

    /** @param size the new size of the font */
    void setSize( float size );

protected:

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    // TODO: render selectable

    /** #Override */
    void setShader( const LightData& lightData );

    /** #Override */
    void draw();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the font to use for rendering
    Font* m_font;
    // the string to render
    std::string m_str;
    // the size of the text
    float m_size;

    // the texture to use for rendering the font to
    GLuint m_texture;
};

} // namespace omi

#endif

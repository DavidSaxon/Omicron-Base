#include "Text.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Text::Text(
        const std::string& id,
        int layer,
        Transform* transform,
        Material material,
        Font* font,
        const std::string& str,
        float size )
    :
    Renderable( id, layer, transform, material ),
    m_font    ( font ),
    m_str     ( str ),
    m_size    ( size )
{
    // create the texture
    glGenTextures( 1, &m_texture );
    glBindTexture( GL_TEXTURE_2D, m_texture );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

//-----------------------------------GETTERS------------------------------------

Font* Text::getFont() const
{
    return m_font;
}

const std::string& Text::getString() const
{
    return m_str;
}

float Text::getSize() const
{
    return m_size;
}

//-----------------------------------SETTERS------------------------------------

void Text::setFont( Font* font )
{
    m_font = font;
}

void Text::setString( const std::string& str )
{
    m_str = str;
}

void Text::setSize( float size )
{
    m_size = size;
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Text::setShader( const LightData& lightData )
{
    // get the OpenGL program
    GLuint program = m_material.shader.getProgram();
    // use the shader
    glUseProgram( program );

    // pass in the matrices to the shader
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelMatrix" ),
        1, GL_FALSE, &m_modelMatrix[0][0] );
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_viewMatrix" ),
        1, GL_FALSE, &m_viewMatrix[0][0] );
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelViewMatrix" ),
        1, GL_FALSE, &m_modelViewMatrix[0][0] );
    glUniformMatrix3fv(
        glGetUniformLocation( program, "u_normalMatrix" ),
        1, GL_FALSE, &m_normalMatrix[0][0] );
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelViewProjectionMatrix" ),
        1, GL_FALSE, &m_modelViewProjectionMatrix[0][0] );

    // pass in colour to the shader
    glUniform4f(
        glGetUniformLocation( program, "u_colour" ),
        m_material.colour.r,
        m_material.colour.g,
        m_material.colour.b,
        m_material.colour.a
    );

    // TODO: loop that shit
    // font texture
    glBindTexture( GL_TEXTURE_2D, m_texture );
    // load character
    FT_Set_Pixel_Sizes( *m_font, 0, 48 );
    FT_Load_Char( *m_font, 'F', FT_LOAD_RENDER );
    glTexImage2D(
          GL_TEXTURE_2D,
          0,
          GL_ALPHA,
          (*m_font)->glyph->bitmap.width,
          (*m_font)->glyph->bitmap.rows,
          0,
          GL_ALPHA,
          GL_UNSIGNED_BYTE,
          (*m_font)->glyph->bitmap.buffer
        );

    // TODO: this can be moved into a common function
    //--------------------------------------------------------------------------
    // lighting
    if ( m_material.isShadeless() )
    {
        // material is not affected by light
        glUniform1i( glGetUniformLocation( program, "u_shadeless" ), 1 );
    }
    else
    {
        // material is affected by light
        glUniform1i( glGetUniformLocation( program, "u_shadeless" ), 0 );

        // pass in ambient light
        glm::vec3 ambientLight =
            renderSettings.getAmbientColour() *
            renderSettings.getAmbientStrength();
        glUniform3f(
            glGetUniformLocation( program, "u_ambientLight" ),
            ambientLight.r, ambientLight.g, ambientLight.b
        );

        // the number of lights
        glUniform1i(
            glGetUniformLocation( program, "u_lightCount" ),
            lightData.types.size()
        );
        if ( lightData.types.size() > 0 )
        {
            // the types of lights
            glUniform1iv(
                glGetUniformLocation( program, "u_lightType" ),
                lightData.types.size(),
                &lightData.types[0]
            );
            // the positions of lights
            glUniform3fv(
                glGetUniformLocation( program, "u_lightPos" ),
                lightData.types.size(),
                &lightData.positions[0]
            );
            // the rotations of lights
            glUniform3fv(
                glGetUniformLocation( program, "u_lightRot" ),
                lightData.types.size(),
                &lightData.rotations[0]
            );
            // the colours of lights
            glUniform3fv(
                glGetUniformLocation( program, "u_lightColour" ),
                lightData.types.size(),
                &lightData.colours[0]
            );
            // the attenuation of lights
            glUniform3fv(
                glGetUniformLocation( program, "u_lightAttenuation" ),
                lightData.types.size(),
                &lightData.attenuations[0]
            );
            // the arcs of lights
            glUniform2fv(
                glGetUniformLocation( program, "u_lightArc" ),
                lightData.types.size(),
                &lightData.arcs[0]
            );
        }
    }

    //--------------------------------PROPERTIES--------------------------------

    // specular property
    Specular* specular = m_material.specular;
    float shininess = 0.0f;
    glm::vec3 specularColour;
    if ( specular != NULL )
    {
        shininess = specular->getShininess();
        specularColour = specular->getColour();
    }
    glUniform1f(
        glGetUniformLocation( program, "u_shininess" ),
        shininess
    );
    glUniform3f(
        glGetUniformLocation( program, "u_specularColour" ),
        specularColour.r,
        specularColour.g,
        specularColour.b
    );
}

void Text::draw()
{
    glBegin(GL_TRIANGLES);

        glTexCoord2f( 1.0f, 1.0f );
        glNormal3f(  0.0f,      0.0f,     1.0f );
        glVertex3f(  1.0f,  1.0f, 0.0f );

        glTexCoord2f( 0.0f, 1.0f );
        glNormal3f(  0.0f,      0.0f,     1.0f );
        glVertex3f( -1.0f,  1.0f, 0.0f );

        glTexCoord2f( 1.0f, 0.0f );
        glNormal3f(  0.0f,      0.0f,     1.0f );
        glVertex3f(  1.0f, -1.0f, 0.0f );

        glTexCoord2f( 0.0f, 0.0f );
        glNormal3f(  0.0f,      0.0f,     1.0f );
        glVertex3f( -1.0f, -1.0f, 0.0f );

        glTexCoord2f( 1.0f, 0.0f );
        glNormal3f(  0.0f,      0.0f,     1.0f );
        glVertex3f(  1.0f, -1.0f, 0.0f );

        glTexCoord2f( 0.0f, 1.0f );
        glNormal3f(  0.0f,      0.0f,     1.0f );
        glVertex3f( -1.0f,  1.0f, 0.0f );

    glEnd();
}

} // namespace omi

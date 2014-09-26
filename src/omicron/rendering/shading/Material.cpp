#include "Material.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Material::Material()
    :
    shader     (),
    colour     ( 1.0f, 1.0f, 1.0f, 1.0f ),
    texture    (),
    m_shadeless( false )
{
}

Material::Material( const Shader&    a_shader,
                    const glm::vec4& a_colour,
                          Texture*   a_texture,
                          unsigned   flags )
    :
    shader     ( a_shader),
    colour     ( a_colour),
    texture    ( a_texture),
    m_flags    ( flags ),
    m_shadeless( false )
{
    parseFlags();
}

Material::Material( const Material& other ) :
    colour     ( other.colour ),
    texture    ( other.texture ),
    shader     ( other.shader ),
    m_shadeless( other.m_shadeless )
{
}

//------------------------------------------------------------------------------
//                                   OPERATORS
//------------------------------------------------------------------------------

const Material& Material::operator=( const Material& other )
{
    shader      = other.shader;
    colour      = other.colour;
    texture     = other.texture;
    m_shadeless = other.m_shadeless;

    return *this;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Material::update()
{
    // update the texture
    if ( texture != NULL )
    {
        texture->update();
    }
}

bool Material::isVisible() const
{
    if ( texture != NULL )
    {
        return texture->isVisible();
    }

    return true;
}

bool Material::isShadeless() const
{
    return m_shadeless;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Material::parseFlags()
{
    m_shadeless = ( m_flags | material::SHADELESS ) != 0;
}

} // namespace omi

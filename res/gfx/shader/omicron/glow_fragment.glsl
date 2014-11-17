#version 130

// the colour
uniform vec4 u_colour;
// if the material has a texture
uniform int u_hasTexture;
// the texture
uniform sampler2D u_texture;
//the texture coords
varying vec2 v_texCoord;

void main()
{
    // TODO: textures
    gl_FragColor = u_colour;
}

#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the colour
uniform vec4 u_colour;
// the texture
uniform sampler2D u_texture;

//the vertex coords
varying vec3 v_vertex;
//the texture coords
varying vec2 v_texCoord;
//the normals
varying vec3 v_normal;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    gl_FragColor = texture2D(u_texture, v_texCoord) * u_colour;
}

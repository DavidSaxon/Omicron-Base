#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the texture
uniform sampler2D u_texture;

//the texture coords
varying vec2 v_texCoord;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    // get texture
    vec4 texCol = texture2D( u_texture, v_texCoord );
    // set performance motion blur transperancy
    texCol.a = 0.5;
    // set colour
    gl_FragColor = texCol;
}

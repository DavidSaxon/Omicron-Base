#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the texture
uniform sampler2D u_texture;

// REMOVE ME
uniform float u_randMul;

//the texture coords
varying vec2 v_texCoord;

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

// REMOVE ME
// generates a pseudo random number
float rand( vec2 co )
{
    return fract( sin( dot( co.xy, vec2( 12.9898, 78.233 ) ) ) * 43758.5453 * u_randMul );
}

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    // set colour
    vec4 texCol = texture2D( u_texture, v_texCoord );
    // apply film grain to output
    float noise = clamp( rand( v_texCoord ), 0.0, 1.0 );
    noise = ( noise * 2.0 ) - 1.0;
    noise *= 0.075;
    texCol.r += noise;
    texCol.g += noise;
    texCol.b += noise;
    gl_FragColor = texCol;
}

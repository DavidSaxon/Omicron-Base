#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the texture
uniform sampler2D u_texture;

// the horizontal resolution
uniform float u_resolution;

//the texture coords
varying vec2 v_texCoord;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    // where we will store the final colour
    vec4 finalColour = vec4( 0.0, 0.0, 0.0, 0.0 );

    // calculate the size of a pixel
    float blur = 1.0 / u_resolution;

    // blur horizontally
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 16.0 * blur, v_texCoord.y ) ) * 0.012318;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 15.0 * blur, v_texCoord.y ) ) * 0.014381;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 14.0 * blur, v_texCoord.y ) ) * 0.016624;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 13.0 * blur, v_texCoord.y ) ) * 0.019024;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 12.0 * blur, v_texCoord.y ) ) * 0.021555;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 11.0 * blur, v_texCoord.y ) ) * 0.024180;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 10.0 * blur, v_texCoord.y ) ) * 0.026854;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 9.0  * blur, v_texCoord.y ) ) * 0.029528;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 8.0  * blur, v_texCoord.y ) ) * 0.032145;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 7.0  * blur, v_texCoord.y ) ) * 0.034647;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 6.0  * blur, v_texCoord.y ) ) * 0.036972;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 5.0  * blur, v_texCoord.y ) ) * 0.039060;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 4.0  * blur, v_texCoord.y ) ) * 0.040857;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 3.0  * blur, v_texCoord.y ) ) * 0.042311;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 2.0  * blur, v_texCoord.y ) ) * 0.043381;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x - 1.0  * blur, v_texCoord.y ) ) * 0.044036;

    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x, v_texCoord.y ) ) * 0.044256;


    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 16.0 * blur, v_texCoord.y ) ) * 0.012318;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 15.0 * blur, v_texCoord.y ) ) * 0.014381;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 14.0 * blur, v_texCoord.y ) ) * 0.016624;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 13.0 * blur, v_texCoord.y ) ) * 0.019024;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 12.0 * blur, v_texCoord.y ) ) * 0.021555;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 11.0 * blur, v_texCoord.y ) ) * 0.024180;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 10.0 * blur, v_texCoord.y ) ) * 0.026854;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 9.0  * blur, v_texCoord.y ) ) * 0.029528;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 8.0  * blur, v_texCoord.y ) ) * 0.032145;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 7.0  * blur, v_texCoord.y ) ) * 0.034647;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 6.0  * blur, v_texCoord.y ) ) * 0.036972;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 5.0  * blur, v_texCoord.y ) ) * 0.039060;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 4.0  * blur, v_texCoord.y ) ) * 0.040857;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 3.0  * blur, v_texCoord.y ) ) * 0.042311;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 2.0  * blur, v_texCoord.y ) ) * 0.043381;
    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x + 1.0  * blur, v_texCoord.y ) ) * 0.044036;

    // boost alpha
    finalColour.a = finalColour.a / finalColour.a / finalColour.a;
    // finalColour.a = 1.0;

    gl_FragColor = finalColour;
}

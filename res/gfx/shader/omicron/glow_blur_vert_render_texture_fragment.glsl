#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the texture
uniform sampler2D u_texture;

// the vertical resolution
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

    // blur vertically
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 16.0 * blur ) ) * 0.012318;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 15.0 * blur ) ) * 0.014381;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 14.0 * blur ) ) * 0.016624;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 13.0 * blur ) ) * 0.019024;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 12.0 * blur ) ) * 0.021555;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 11.0 * blur ) ) * 0.024180;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 10.0 * blur ) ) * 0.026854;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 9.0  * blur ) ) * 0.029528;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 8.0  * blur ) ) * 0.032145;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 7.0  * blur ) ) * 0.034647;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 6.0  * blur ) ) * 0.036972;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 5.0  * blur ) ) * 0.039060;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 4.0  * blur ) ) * 0.040857;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 3.0  * blur ) ) * 0.042311;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 2.0  * blur ) ) * 0.043381;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y - 1.0  * blur ) ) * 0.044036;

    finalColour += texture2D( u_texture,
        vec2( v_texCoord.x, v_texCoord.y ) ) * 0.044256;

    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 16.0 * blur ) ) * 0.012318;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 15.0 * blur ) ) * 0.014381;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 14.0 * blur ) ) * 0.016624;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 13.0 * blur ) ) * 0.019024;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 12.0 * blur ) ) * 0.021555;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 11.0 * blur ) ) * 0.024180;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 10.0 * blur ) ) * 0.026854;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 9.0  * blur ) ) * 0.029528;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 8.0  * blur ) ) * 0.032145;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 7.0  * blur ) ) * 0.034647;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 6.0  * blur ) ) * 0.036972;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 5.0  * blur ) ) * 0.039060;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 4.0  * blur ) ) * 0.040857;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 3.0  * blur ) ) * 0.042311;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 2.0  * blur ) ) * 0.043381;
    finalColour += texture2D( u_texture,
            vec2( v_texCoord.x, v_texCoord.y + 1.0  * blur ) ) * 0.044036;

    // boost alpha
    finalColour.a = finalColour.a / finalColour.a / finalColour.a;
    // finalColour.a = 1.0;

    gl_FragColor = finalColour;
}

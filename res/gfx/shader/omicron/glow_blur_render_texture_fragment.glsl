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

    // set colour
    vec4 finalColour;

    // TODO: how to choose blur amount for glow?? needs to come from colour??
    float u_Blur = 0.8;

    // TODO: needs to be a further reaching blur filter
    // needs to take nearest pixels!
    // blur colours
    vec2 offset0 = vec2(v_texCoord);
    offset0.y -= 0.002;
    vec4 col0 = texture2D(u_texture, offset0) * (u_Blur / 4.0);

    vec2 offset1 = vec2(v_texCoord);
    offset1.x -= 0.002;
    vec4 col1 = texture2D(u_texture, offset1) * (u_Blur / 4.0);

    vec4 col2 = texture2D(u_texture, v_texCoord) * (1.0 - u_Blur);

    vec2 offset3 = vec2(v_texCoord);
    offset3.x += 0.002;
    vec4 col3 = texture2D(u_texture, offset3) * (u_Blur / 4.0);

    vec2 offset4 = vec2(v_texCoord);
    offset4.y += 0.002;
    vec4 col4 = texture2D(u_texture, offset4) * (u_Blur / 4.0);

    finalColour = col0 + col1 + col2 + col3 + col4;

    gl_FragColor = finalColour;
}

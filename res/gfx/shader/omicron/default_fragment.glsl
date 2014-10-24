#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the view matrix
uniform mat4 u_viewMatrix;

// the colour
uniform vec4 u_colour;
// if the material has a texture
uniform int u_hasTexture;
// the texture
uniform sampler2D u_texture;

// if the material is shadeless
uniform int u_shadeless;
//the ambient light
uniform vec3 u_ambientLight;

// the number of lights
uniform int u_lightCount;
// the light types
uniform int u_lightType[8];
// the light positions
uniform vec3 u_lightPos[8];
// the light colours
uniform vec3 u_lightColour[8];

//the texture coords
varying vec2 v_texCoord;
//the normal
varying vec3 v_normal;
// the eye position
varying vec3 v_eyePos;

// // the vertex position in camera space
// varying vec3 v_vertexCameraSpace;
// // the direction of the eye
// varying vec3 v_eyeDirection;
// // the normal in camera space
// varying vec3 v_normalCameraSpace;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    //---------------------------------MATERIAL---------------------------------

    // the colour of the material
    // vec4 material = u_colour;
    vec4 material = u_colour;

    //apply texturing
    vec4 textureColour = texture2D(u_texture, v_texCoord);
    if (u_hasTexture != 0) {

        material *= textureColour;
    }

    //---------------------------------LIGHTING---------------------------------

    if ( u_shadeless != 0 )
    {
        gl_FragColor = material;
    }
    else
    {
        // TODO: these should come from material
        float shininess = 128.0;
        vec3 materialSpecular = vec3( 1.0, 1.0, 1.0 );

        // the light value
        vec3 light = u_ambientLight;
        // vec3 light = vec3( 0.0, 0.0, 0.0 );

        // normalize the normal
        vec3 N = normalize( v_normal );

        for ( int i = 0; i < u_lightCount; ++i )
        {

            // compute the light position
            vec3 lightDir = normalize( u_lightPos[i] );
            // compute the dot product between the normal and light direction
            float cosThetha = max( dot( N, lightDir ), 0.0 );
            if ( cosThetha > 0.0 )
            {
                // compute and add diffuse colour
                light += u_lightColour[i] * cosThetha;
                // calculate the half vector
                vec3 half = normalize( normalize( v_eyePos ) + u_lightPos[i] );
                // compute specular
                float cosAlpha = max( dot( N, half ), 0.0 );
                light += materialSpecular * u_lightColour[i] *
                        pow( cosAlpha, shininess );
            }
        }

        gl_FragColor = material * vec4( light, 1.0 );
    }
}

#version 130

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
// the light rotations
uniform vec3 u_lightRot[8];
// the light colours
uniform vec3 u_lightColour[8];
// the light attenuations
uniform vec3 u_lightAttenuation[8];
// the light arcs
uniform vec2 u_lightArc[8];

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

        // normalize the normal
        vec3 N = normalize( v_normal );

        for ( int i = 0; i < u_lightCount; ++i )
        {
            // calculate the half vector

            // directional light
            if ( u_lightType[i] == 0 )
            {
                // compute the light position
                vec3 lightDir = normalize( u_lightPos[i] );
                // compute angle between normal and light
                float cosThetha = max( dot( N, lightDir ), 0.0 );
                if ( cosThetha > 0.0 )
                {
                    // compute and add diffuse colour
                    light += u_lightColour[i] * cosThetha;
                    // compute half vector
                    vec3 H =
                        normalize( normalize( v_eyePos ) + u_lightPos[i] );
                    // compute specular
                    float cosAlpha = max( dot( N, H ), 0.0 );
                    light += materialSpecular * u_lightColour[i] *
                            pow( cosAlpha, shininess );
                }
            }
            // point light
            else if ( u_lightType[i] == 1 )
            {
                // compute the light position
                vec3 lightDir = u_lightPos[i] + v_eyePos;
                // the distance to the light source
                float distance = length( lightDir );
                // compute angle between normal and light
                float cosThetha = max( dot( N, normalize( lightDir ) ), 0.0 );
                if ( cosThetha > 0.0 )
                {
                    // calculate attenuation
                    float attenuation = 1.0 / (
                        u_lightAttenuation[i].x +
                        ( u_lightAttenuation[i].y * distance ) +
                        ( u_lightAttenuation[i].z * distance * distance ) );
                    // apply diffuse
                    light += attenuation * u_lightColour[i] * cosThetha;
                    // compute half vector
                    vec3 H =
                        normalize( normalize( v_eyePos ) +
                                   normalize( lightDir ) );
                    // compute specular
                    float cosAlpha = max( dot ( N, H ), 0.0 );
                    light += attenuation * materialSpecular * u_lightColour[i] *
                            pow( cosAlpha, shininess );
                }
            }
            // spot light
            else if ( u_lightType[i] == 2 )
            {
                // compute the light position
                vec3 lightDir = u_lightPos[i] + v_eyePos;
                // the distance to the light source
                float distance = length( lightDir );
                // compute angle between normal and light
                float cosThetha = max( dot( N, normalize( lightDir ) ), 0.0 );
                if ( cosThetha > 0.0 )
                {
                    // calculate the spot light effect
                    float spotEffect =
                        dot( normalize( u_lightRot[i] ),
                             normalize( -lightDir ) );
                    if ( spotEffect > u_lightArc[i].x )
                    {
                        spotEffect = smoothstep( u_lightArc[i].x, u_lightArc[i].y, spotEffect );
                        // calculate attenuation
                        float attenuation = spotEffect / (
                            u_lightAttenuation[i].x +
                            ( u_lightAttenuation[i].y * distance ) +
                            ( u_lightAttenuation[i].z * distance * distance ) );
                        // apply diffuse
                        light += attenuation * u_lightColour[i] * cosThetha;
                        // compute half vector
                        vec3 H =
                            normalize( normalize( v_eyePos ) +
                                        normalize( lightDir ) );
                        // compute specular
                        float cosAlpha = max( dot ( N, H ), 0.0 );
                        light += attenuation * materialSpecular *
                                u_lightColour[i] *
                                pow( cosAlpha, shininess );
                    }
                }
            }
        }

        gl_FragColor = material * vec4( light, 1.0 );
    }
}

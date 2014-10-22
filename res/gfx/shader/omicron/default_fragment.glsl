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

// the number of point lights
uniform int u_PointCount;
// the point light positions
uniform vec3 u_PointPos[8];
// the point light distances
uniform float u_PointDis[8];
// the point light colours
uniform vec3 u_PointColour[8];

//the texture coords
varying vec2 v_texCoord;
// TESTING
varying vec4 v_colour;

//the vertex coords
varying vec3 v_vertex;
//the normals
varying vec3 v_normal;

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
    vec4 material = v_colour;

    //apply texturing
    vec4 textureColour = texture2D(u_texture, v_texCoord);
    if (u_hasTexture != 0) {

        material *= textureColour;
    }

    //---------------------------------LIGHTING---------------------------------

    gl_FragColor = material;

    // if ( u_shadeless != 0 )
    // {
    //     gl_FragColor = material;
    // }
    // else
    // {
    //     // normalize normal
    //     vec3 N = normalize( v_normal );

    //     // apply ambient light
    //     vec3 light = u_ambientLight;

    //     // apply point lights
    //     for ( int i = 0; i < u_PointCount; ++i )
    //     {
    //         vec3 L = normalize( u_PointPos[i] - v_vertex );
    //         vec3 E = normalize( -v_vertex );
    //         vec3 R = normalize( -reflect( L, N ) );

    //         // calculate diffuse
    //         vec3 diffuse = u_PointColour[i] * max( dot( N, L ), 0.0 );
    //         diffuse = clamp( diffuse, 0.0, 1.0 );

    //         // calculate specular
    //         vec3 specular = vec3( 1.0 ) * pow( max( dot( R, E ), 0.0 ), 50.0 );
    //         specular = clamp( specular, 0.0, 1.0 );

    //         light += diffuse + specular;

    //         // // calculate the distance from the light
    //         // float distance = length( u_PointPos[i] - v_vertex ) / u_PointDis[i];
    //         // // calculate the direction from the light
    //         // vec3 lightVector = normalize( u_PointPos[i] - v_vertex );
    //         // // calculate the dot product between the normal and light vector
    //         // float diffuse = max( dot( v_normal, lightVector ), 0.0 );
    //         // // add attenuation
    //         // float attenuation =
    //         //     ( 1.0 / ( 1.0 + ( 0.25 * distance * distance ) ) );
    //         // diffuse *= attenuation;
    //         // // add colour
    //         // vec3 diffuseVector = vec3( diffuse, diffuse, diffuse );
    //         // diffuseVector *= u_PointColour[i];

    //         // // specular component
    //         // // vec3 lightDirection =
    //         // //     ( u_viewMatrix * vec4( u_PointPos[i], 1.0 ) ).xyz;
    //         // // lightDirection = lightDirection + v_eyeDirection;
    //         // // vec3 R = reflect( -lightDirection, normalize( lightDirection ) );
    //         // // float specular = clamp( dot( v_eyeDirection, R ), 0.0, 1.0 );
    //         // // specular = pow( specular, 5 ) / ( distance * distance );
    //         // // vec3 specularVector = vec3( specular, specular, specular );

    //         // // vec3 R = reflect( -lightVector, v_normalCameraSpace );
    //         // // vec3 viewDirection

    //         // // add to total light
    //         // // light += diffuseVector + specularVector;
    //         // light += diffuseVector;
    //     }

    //     gl_FragColor = material * vec4(light, 1.0);
    // }
}

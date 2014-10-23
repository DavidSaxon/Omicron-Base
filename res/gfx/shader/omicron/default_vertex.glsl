#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

//-----------------------------------UNIFORM------------------------------------

// the model matrix
uniform mat4 u_modelMatrix;
// the view matrix
uniform mat4 u_viewMatrix;
// the model view matrix
uniform mat4 u_modelViewMatrix;
// the normal matrix
uniform mat4 u_normalMatrix;
// the model, view, projection matrix
uniform mat4 u_modelViewProjectionMatrix;

// the number of point lights
uniform int u_PointCount;
// the point light positions
uniform vec3 u_PointPos[8];
// the point light distances
uniform float u_PointDis[8];
// the point light colours
uniform vec3 u_PointColour[8];

// REMOVE ME
// the colour
uniform vec4 u_colour;

//-----------------------------------VARYING------------------------------------

// the texture coords
varying vec2 v_texCoord;
// the normal
varying vec3 v_normal;

// // the vertex coords
// varying vec3 v_vertex;


//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    //set the texture coords
    v_texCoord = vec2( gl_MultiTexCoord0 );
    // transform the normal into eye space
    v_normal = normalize( vec3( u_normalMatrix * vec4( gl_Normal, 0.0 ) ) );
    //


    // //set the vertex coord
    // v_vertex = vec3( u_modelMatrix * gl_Vertex );
    // //set the normal
    // v_normal = vec3( u_normalMatrix * vec4( gl_Normal, 0.0 ) );

    //---------------------------------LIGHTING---------------------------------
    // TODO: these should come from material/light
    // float shininess = 128.0;
    // vec3 materialSpecular = vec3( 1.0, 1.0, 1.0 );
    // // TODO: this should just ben light colour??
    // vec3 lightSpecular = u_PointColour[0];

    // // transform the normal into eye space
    // vec3 normal = normalize( vec3( u_normalMatrix * vec4( gl_Normal, 0.0 ) ) );

    // // get the eye position
    // // TODO: should this just use model view?????
    // vec3 eyePos = -vec3( u_modelViewProjectionMatrix * gl_Vertex );

    // // transform the light position into eye space
    // vec3 lightPos = vec3( u_viewMatrix * vec4( u_PointPos[0], 0.0 ) );
    // // get the direction of the light
    // vec3 lightDir = normalize( lightPos );

    // // half vector
    // vec3 half = normalize( lightPos + eyePos );

    // // compute the cosine of the angle between the normal and light direction
    // float cosThetha = max( dot( normal, lightDir), 0.0 );
    // // compute the diffuse colour
    // vec3 diffuse = u_PointColour[0] * cosThetha;

    // // specular
    // vec3 specular = vec3( 0.0, 0.0, 0.0 );
    // if ( cosThetha > 0.0 )
    // {
    //     float cosAlpha = max( dot( normal, half ), 0.0 );
    //     specular =
    //         materialSpecular * lightSpecular * pow( cosAlpha, shininess );
    // }

    // vec3 colour = diffuse;
    // colour += specular;
    // v_colour = u_colour * vec4( colour, 1.0 );

    //set the position
    gl_Position = u_modelViewProjectionMatrix * gl_Vertex;
}

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
uniform mat3 u_normalMatrix;
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
// the eye position
varying vec3 v_eyePos;


//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    //set the texture coords
    v_texCoord = vec2( gl_MultiTexCoord0 );
    // transform the normal into eye space
    // v_normal = normalize( vec3( u_normalMatrix * vec4( gl_Normal, 0.0 ) ) );
    v_normal = normalize( u_normalMatrix * gl_Normal );
    // calculate the eye position
    v_eyePos = -vec3( u_modelViewMatrix * gl_Vertex );

    //set the position
    gl_Position = u_modelViewProjectionMatrix * gl_Vertex;
}

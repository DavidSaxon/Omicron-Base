#version 130

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
    // v_normal = normalize( vec3( u_modelViewMatrix * vec4( gl_Normal, 0.0 ) ) );
    v_normal = normalize( u_normalMatrix * gl_Normal );
    // calculate the eye position
    v_eyePos = -vec3( u_modelViewMatrix * gl_Vertex );

    //set the position
    gl_Position = u_modelViewProjectionMatrix * gl_Vertex;
}

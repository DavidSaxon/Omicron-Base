#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

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

// the vertex coords
varying vec3 v_vertex;
// the texture coords
varying vec2 v_texCoord;
// the normals
varying vec3 v_normal;

// the vertex position in camera space
varying vec3 v_vertexCameraSpace;
// the direction of the eye
varying vec3 v_eyeDirection;
// the normal in camera space
varying vec3 v_normalCameraSpace;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    //set the vertex coord
    v_vertex = vec3( u_modelMatrix * gl_Vertex );
    //set the normal
    v_normal = vec3( u_normalMatrix * vec4( gl_Normal, 0.0 ) );
    //set the texture coords
    v_texCoord = vec2( gl_MultiTexCoord0 );

    // calculate the vertex position in camera space
    v_vertexCameraSpace = ( u_modelViewMatrix * gl_Vertex ).xyz;
    // calculate the eye direction
    v_eyeDirection = normalize( -v_vertexCameraSpace );

    v_normalCameraSpace = (u_normalMatrix * vec4( gl_Normal, 0.0 ) ).xyz;

    //set the position
    gl_Position = u_modelViewProjectionMatrix * gl_Vertex;
}

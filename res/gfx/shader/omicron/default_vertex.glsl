#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the model, view, projection matrix
uniform mat4 u_modelViewProjectionMatrix;

// the vertex coords
varying vec3 v_vertex;
// the texture coords
varying vec2 v_texCoord;
// the normals
varying vec3 v_normal;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    //set the vertex coord
    v_vertex = vec3( u_modelViewProjectionMatrix * gl_Vertex );
    //set the normal
    v_normal = normalize( gl_NormalMatrix * gl_Normal );
    //set the texture coords
    v_texCoord = vec2( gl_MultiTexCoord0 );

    //set the position
    gl_Position = u_modelViewProjectionMatrix * gl_Vertex;
}

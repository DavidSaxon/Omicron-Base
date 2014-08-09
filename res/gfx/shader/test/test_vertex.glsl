#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the vertex coords 
varying vec3 v_Vertex;
// the texture coords
varying vec2 v_TexCoord;
// the normals
varying vec3 v_Normal;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {
    
    //set the vertex coord
    v_Vertex = vec3(gl_ModelViewMatrix * gl_Vertex);
    //set the normal
    v_Normal = normalize(gl_NormalMatrix * gl_Normal);
    //set the texture coords
    v_TexCoord = vec2(gl_MultiTexCoord0);

    //set the position
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}

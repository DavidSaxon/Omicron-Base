#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

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

//the vertex coords
varying vec3 v_vertex;
//the texture coords
varying vec2 v_texCoord;
//the normals
varying vec3 v_normal;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    //---------------------------------MATERIAL---------------------------------

    // the colour of the material
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
        // apply ambient light
        vec3 light = u_ambientLight;

        vec3 pointPos = vec3( 0.0, 1.0, 0.0 );

        // apply point lights
        // calculate the distance from the light
        float distance = length( pointPos - v_vertex ) / 1.0; // TODO: distance
        // calculate the direction from the light
        vec3 lightVector = normalize( pointPos - v_vertex );
        // calculate the dot product between the normal and light vector
        float diffuse = max( dot( v_normal, lightVector ), 0.0 );
        // add attenuation
        diffuse = diffuse * ( 1.0 / ( 1.0 + ( 0.25 * distance * distance ) ) );
        // calculate the diffuse vector
        vec3 diffuseVector = vec3( diffuse, diffuse, diffuse );
        // TODO: add colour

        // TODO:
        light += diffuseVector;

        gl_FragColor = material * vec4(light, 1.0);
    }
}

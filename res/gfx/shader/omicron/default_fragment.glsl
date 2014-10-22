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

// the number of point lights
uniform int u_PointCount;
// the point light positions
uniform vec3 u_PointPos[8];
// the point light distances
uniform float u_PointDis[8];
// the point light colours
uniform vec3 u_PointColour[8];

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

        // apply point lights
        for ( int i = 0; i < u_PointCount; ++i )
        {
            // calculate the distance from the light
            float distance = length( u_PointPos[i] - v_vertex ) / u_PointDis[i];
            // calculate the direction from the light
            vec3 lightVector = normalize( u_PointPos[i] - v_vertex );
            // calculate the dot product between the normal and light vector
            float diffuse = max( dot( v_normal, lightVector ), 0.0 );
            // add attenuation
            diffuse *= ( 1.0 / ( 1.0 + ( 0.25 * distance * distance ) ) );
            // add colour
            vec3 diffuseVector = vec3( diffuse, diffuse, diffuse );
            diffuseVector *= u_PointColour[i];
            // add to total light
            light += diffuseVector;
        }

        gl_FragColor = material * vec4(light, 1.0);
    }
}

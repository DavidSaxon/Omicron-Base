#include "KeyFrameMesh.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

KeyFrameMesh::KeyFrameMesh(
        const std::string& id,
        int layer,
        Transform* transform,
        std::map<std::string, std::vector<Geometry*>> geometry,
        Material material ) :
    Renderable( id, layer, transform, material ),
    m_geometry( geometry )
{
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KeyFrameMesh::draw()
{
    // TODO: get actual interpolation data
    Geometry* geo = m_geometry["walk"][0];

    glBegin( GL_TRIANGLES );
    for ( unsigned i = 0; i < geo->vertices.size(); ++i ) {

        // draw normals if the geometry contains them
        if ( geo->normals.size() > 0 )
        {
            glNormal3f(
                geo->normals[i].x,
                geo->normals[i].y,
                geo->normals[i].z
            );
        }

        // TODO: check if texture exists too
        // draw the texture coordinates if the exists
        if ( geo->uv.size() > 0 )
        {
            glTexCoord2f( geo->uv[i].x, geo->uv[i].y );
        }

        // render vertices
        glVertex3f(
            geo->vertices[i].x,
            geo->vertices[i].y,
            geo->vertices[i].z
        );
    }
    glEnd();
}


} // namespace omi

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
    m_geometry( geometry ),
    m_timer   ( 0.0f ),
    m_frame   ( 0 )
{
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KeyFrameMesh::draw()
{
    // increase the timer
    m_timer += 0.018f * omi::fpsManager.getTimeScale();
    if ( m_timer > 1.0f )
    {
        m_timer -= 1.0f;
        ++m_frame;
    }
    unsigned gSize = m_geometry[ "walk" ].size();
    // calculate ratios
    float r1 = 1.0f - m_timer;
    float r2 = m_timer;

    // TODO: get actual interpolation data
    Geometry* geo_1 = m_geometry[ "walk" ][ m_frame % gSize ];
    Geometry* geo_2 = m_geometry[ "walk" ][ ( m_frame + 1 ) % gSize ];

    glBegin( GL_TRIANGLES );
    for ( unsigned i = 0; i < geo_1->vertices.size(); ++i ) {

        // draw normals if the geometry contains them
        if ( geo_1->normals.size() > 0 )
        {
            glNormal3f(
                ( geo_1->normals[i].x * r1 ) + ( geo_2->normals[i].x * r2 ),
                ( geo_1->normals[i].y * r1 ) + ( geo_2->normals[i].y * r2 ),
                ( geo_1->normals[i].z * r1 ) + ( geo_2->normals[i].z * r2 )
            );
        }

        // draw the texture coordinates if the exists
        if ( geo_1->uv.size() > 0 )
        {
            glTexCoord2f(
                ( geo_1->uv[i].x * r1 ) + ( geo_2->uv[i].x * r2 ),
                ( geo_1->uv[i].y * r1 ) + ( geo_2->uv[i].y * r2 )
            );
        }

        // render vertices
        glVertex3f(
            ( geo_1->vertices[i].x * r1 ) + ( geo_2->vertices[i].x * r2 ),
            ( geo_1->vertices[i].y * r1 ) + ( geo_2->vertices[i].y * r2 ),
            ( geo_1->vertices[i].z * r1 ) + ( geo_2->vertices[i].z * r2 )
        );
    }
    glEnd();
}


} // namespace omi

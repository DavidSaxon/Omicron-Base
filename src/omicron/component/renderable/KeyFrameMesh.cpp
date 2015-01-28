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
        std::map<std::string, std::vector<unsigned>> frames,
        Material material ) :
    Renderable( id, layer, transform, material ),
    m_geometry( geometry ),
    m_frameMap( frames ),
    m_geo1    ( NULL ),
    m_geo2    ( NULL ),
    m_currAni ( "walk" ),
    m_frame   ( 0.0f ),
    m_key     ( 0 ),
    m_r1      ( 1.0f ),
    m_r2      ( 0.0f )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KeyFrameMesh::update()
{
    // super call
    Renderable::update();

    // get the current number if keys
    unsigned length = m_geometry[ m_currAni ].size();

    // increase the frame
    m_frame += omi::fpsManager.getTimeScale();
    while ( m_frame > static_cast<float>( m_frameMap[ m_currAni ][ m_key ] ) )
    {
        m_frame -= static_cast<float>( m_frameMap[ m_currAni ][ m_key ] );
        m_key = ( m_key + 1 ) % length;
    }

    // get the geometries are interpolating between
    m_geo1 = m_geometry[ m_currAni ][ m_key ];
    m_geo2 = m_geometry[ m_currAni ][ ( m_key + 1 ) % length ];

    // calculate ratio
    m_r2 = m_frame / static_cast<float>( m_frameMap[ m_currAni ][ m_key ] );
    m_r1 = 1.0f - m_r2;
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KeyFrameMesh::draw()
{
    glBegin( GL_TRIANGLES );
    for ( unsigned i = 0; i < m_geo1->vertices.size(); ++i ) {

        // draw normals if the geometry contains them
        if ( m_geo1->normals.size() > 0 )
        {
            glNormal3f(
                ( m_geo1->normals[i].x * m_r1 ) +
                ( m_geo2->normals[i].x * m_r2 ),
                ( m_geo1->normals[i].y * m_r1 ) +
                ( m_geo2->normals[i].y * m_r2 ),
                ( m_geo1->normals[i].z * m_r1 ) +
                ( m_geo2->normals[i].z * m_r2 )
            );
        }

        // draw the texture coordinates if the exists
        if ( m_geo1->uv.size() > 0 )
        {
            glTexCoord2f(
                ( m_geo1->uv[i].x * m_r1 ) + ( m_geo2->uv[i].x * m_r2 ),
                ( m_geo1->uv[i].y * m_r1 ) + ( m_geo2->uv[i].y * m_r2 )
            );
        }

        // render vertices
        glVertex3f(
            ( m_geo1->vertices[i].x * m_r1 ) + ( m_geo2->vertices[i].x * m_r2 ),
            ( m_geo1->vertices[i].y * m_r1 ) + ( m_geo2->vertices[i].y * m_r2 ),
            ( m_geo1->vertices[i].z * m_r1 ) + ( m_geo2->vertices[i].z * m_r2 )
        );
    }
    glEnd();
}


} // namespace omi

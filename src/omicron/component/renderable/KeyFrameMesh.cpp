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
    m_geo1    ( NULL ),
    m_geo2    ( NULL ),
    m_timer   ( 0.0f ),
    m_frame   ( 0 )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KeyFrameMesh::update()
{
    // super call
    Renderable::update();

    // increase the timer
    m_timer += 0.05f * omi::fpsManager.getTimeScale();
    if ( m_timer > 1.0f )
    {
        m_timer -= 1.0f;
        ++m_frame;
    }
    unsigned gSize = m_geometry[ "walk" ].size();

    // get the geometries are interpolating between
    // TODO: this only needs to happen on frame update?
    m_geo1 = m_geometry[ "walk" ][ m_frame % gSize ];
    m_geo2 = m_geometry[ "walk" ][ ( m_frame + 1 ) % gSize ];
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KeyFrameMesh::draw()
{
    // calculate ratios
    float r1 = 1.0f - m_timer;
    float r2 = m_timer;

    glBegin( GL_TRIANGLES );
    for ( unsigned i = 0; i < m_geo1->vertices.size(); ++i ) {

        // draw normals if the geometry contains them
        if ( m_geo1->normals.size() > 0 )
        {
            glNormal3f(
                ( m_geo1->normals[i].x * r1 ) + ( m_geo2->normals[i].x * r2 ),
                ( m_geo1->normals[i].y * r1 ) + ( m_geo2->normals[i].y * r2 ),
                ( m_geo1->normals[i].z * r1 ) + ( m_geo2->normals[i].z * r2 )
            );
        }

        // draw the texture coordinates if the exists
        if ( m_geo1->uv.size() > 0 )
        {
            glTexCoord2f(
                ( m_geo1->uv[i].x * r1 ) + ( m_geo2->uv[i].x * r2 ),
                ( m_geo1->uv[i].y * r1 ) + ( m_geo2->uv[i].y * r2 )
            );
        }

        // render vertices
        glVertex3f(
            ( m_geo1->vertices[i].x * r1 ) + ( m_geo2->vertices[i].x * r2 ),
            ( m_geo1->vertices[i].y * r1 ) + ( m_geo2->vertices[i].y * r2 ),
            ( m_geo1->vertices[i].z * r1 ) + ( m_geo2->vertices[i].z * r2 )
        );
    }
    glEnd();
}


} // namespace omi

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
        const std::string& defaultAni,
        Material material ) :
    Renderable  ( id, layer, transform, material ),
    m_geometry  ( geometry ),
    m_frameMap  ( frames ),
    m_defaultAni( defaultAni ),
    m_geo1      ( NULL ),
    m_geo2      ( NULL ),
    m_currAni   ( defaultAni ),
    m_prevAni   ( "" ),
    m_transition( -1 ),
    m_frame     ( 0.0f ),
    m_key       ( 0 ),
    m_r1        ( 1.0f ),
    m_r2        ( 0.0f )
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

    // get the current frame count
    float frameCount = static_cast<float>( m_frameMap[ m_currAni ][ m_key ] );

    // if we are in a transition use transition values
    if ( m_transition >= 0 )
    {
        length = 1;
        frameCount = static_cast<float>( m_transition );
    }

    // increase the frame
    m_frame += omi::fpsManager.getTimeScale();
    if ( m_frame > frameCount )
    {
        m_frame -= frameCount;
        m_key = ( m_key + 1 ) % length;

        // remove any transitions
        if ( m_transition >= 0 )
        {
            m_transition = -1;
            m_prevAni = "";
            m_key = 0;
        }
    }

    // get the geometries are interpolating between
    m_geo1 = m_geometry[ m_currAni ][ m_key ];
    if ( m_transition >= 0 )
    {
        m_geo1 = m_geometry[ m_prevAni ][ m_key ];
        m_geo2 = m_geometry[ m_currAni ][ 0 ];
    }
    else
    {
        m_geo1 = m_geometry[ m_currAni ][ m_key ];
        m_geo2 = m_geometry[ m_currAni ][ ( m_key + 1 ) % length ];
    }

    // calculate ratio
    m_r2 = m_frame / frameCount;
    m_r1 = 1.0f - m_r2;
}

void KeyFrameMesh::transition( const std::string animation, unsigned frames )
{
    m_prevAni = m_currAni;
    m_currAni = animation;
    m_transition = static_cast<int>( frames );
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

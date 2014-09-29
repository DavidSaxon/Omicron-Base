#include "Camera.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Camera::Camera( const std::string& id,
                     cam::Mode    mode,
                     Transform*   transform )
    :
    Component  ( id ),
    m_mode     ( mode ),
    m_transform( transform ),
    m_fov      ( 60.0f ),
    m_nearClip ( 0.001f ),
    m_farClip  ( 1000.0f )
{
}

Camera::Camera( const std::string& id,
                      cam::Mode    mode,
                      Transform*   transform,
                      float        fov )
    :
    Component  ( id ),
    m_mode     ( mode ),
    m_transform( transform ),
    m_fov      ( fov ),
    m_nearClip ( 0.001f ),
    m_farClip  ( 1000.0f )
{
}

Camera::Camera( const std::string& id,
                      cam::Mode    mode,
                      Transform*   transform,
                      float        nearClip,
                      float        farClip )
    :
    Component  ( id ),
    m_mode     ( mode ),
    m_transform( transform ),
    m_fov      ( 60.0f ),
    m_nearClip ( nearClip ),
    m_farClip  ( farClip )
{
}

Camera::Camera( const std::string& id,
                      cam::Mode    mode,
                      Transform*   transform,
                      float        fov,
                      float        nearClip,
                      float        farClip )
    :
    Component  ( id ),
    m_mode     ( mode ),
    m_transform( transform ),
    m_fov      ( fov ),
    m_nearClip ( nearClip ),
    m_farClip  ( farClip )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

component::Type Camera::getType() const
{
    return component::CAMERA;
}

void Camera::apply()
{

    // TODO: REMOVE ME
    //--------------------------------------------------------------------------
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (m_mode == cam::PERSPECTIVE) {

        // set up the projection matrix
        gluPerspective(m_fov,
            displaySettings.getSize().x / displaySettings.getSize().y,
            m_nearClip, m_farClip);
    }
    else {

        // set up the orthographic matrix
        float aspectRatio =
            displaySettings.getSize().x / displaySettings.getSize().y;
        glOrtho(-aspectRatio, aspectRatio, -1.0f, 1.0f, m_nearClip, m_farClip);
    }

    // set up the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // scale
    glm::vec3 scale(m_transform->computeScale());
    glScalef(scale.x, scale.y, scale.z);
    //rotation
    glm::vec3 rotation(m_transform->computeRotation());
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
    // translation
    glm::vec3 translation = m_transform->computeTranslation();
    glTranslatef(translation.x, translation.y, translation.z);
    //--------------------------------------------------------------------------

    //set up the projection matrix
    float aspectRatio =
        displaySettings.getSize().x / displaySettings.getSize().y;
    if ( m_mode == cam::PERSPECTIVE )
    {
        m_projectionMatrix =
            glm::perspective( m_fov, aspectRatio, m_nearClip, m_farClip );
    }
    else
    {
        m_projectionMatrix = glm::ortho(
            -aspectRatio, aspectRatio, -1.0f, 1.0f, m_nearClip, m_farClip );
    }

    // set up the view matrix
    m_viewMatrix = glm::lookAt(
        glm::vec3( 0, 0, 1 ),
        glm::vec3( 0, 0, 0 ),
        glm::vec3( 0, 1, 0 )
    );
    // TODO: REMOVE BRACES
    {
    // apply transformations to the view matrix
    glm::vec3 scale( m_transform->computeScale() );
    m_viewMatrix *= glm::scale( scale );
    glm::vec3 rotation( m_transform->computeRotation() );
    m_viewMatrix *= glm::rotate( rotation.x, glm::vec3( 1.0f, 0.0f, 0.0f ) );
    m_viewMatrix *= glm::rotate( rotation.y, glm::vec3( 0.0f, 1.0f, 0.0f ) );
    m_viewMatrix *= glm::rotate( rotation.z, glm::vec3( 0.0f, 0.0f, 1.0f ) );
    glm::vec3 translation( m_transform->computeTranslation() );
    m_viewMatrix *= glm::translate( translation );
    }
}

//-----------------------------------GETTERS------------------------------------

cam::Mode Camera::getMode() const
{
    return m_mode;
}

Transform* Camera::getTransform()
{
    return m_transform;
}

const glm::mat4& Camera::getProjectionMatrix()
{
    return m_projectionMatrix;
}

const glm::mat4& Camera::getViewMatrix()
{
    return m_viewMatrix;
}

float Camera::getFOV() const
{
    return m_fov;
}

float Camera::getNearClippingPlane() const
{
    return m_nearClip;
}

float Camera::getFarClippingPlane() const
{
    return m_farClip;
}

//-----------------------------------SETTERS------------------------------------

void Camera::setMode( cam::Mode mode )
{
    m_mode = mode;
}

void Camera::setTransform( Transform* transform )
{
    m_transform = transform;
}

void Camera::setFOV( float fov )
{
    m_fov = fov;
}

void Camera::setNearClip( float nearClip )
{
    m_nearClip = nearClip;
}

void Camera::setFarClip( float farClip )
{
    m_farClip = farClip;
}

} // namespace omi

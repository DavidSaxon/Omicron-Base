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
    // get the computed transformations
    glm::vec3 translation( m_transform->computeTranslation() );
    glm::vec3 rotation(m_transform->computeRotation());
    glm::vec3 scale(m_transform->computeScale());

    // projection matrix
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

    // view matrix
    m_viewMatrix = glm::lookAt(
        glm::vec3( 0, 0, 1 ),
        glm::vec3( 0, 0, 0 ),
        glm::vec3( 0, 1, 0 )
    );
    // scale
    m_viewMatrix *= glm::scale( scale );
    // rotation
    m_viewMatrix *= glm::rotate( rotation.x, glm::vec3( 1.0f, 0.0f, 0.0f ) );
    m_viewMatrix *= glm::rotate( rotation.y, glm::vec3( 0.0f, 1.0f, 0.0f ) );
    m_viewMatrix *= glm::rotate( rotation.z, glm::vec3( 0.0f, 0.0f, 1.0f ) );
    // translation
    m_viewMatrix *= glm::translate( translation );
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

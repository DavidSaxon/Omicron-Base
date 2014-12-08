#include "Camera.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

namespace {

static const float SHADOW_CAM_SIZE = 5.0f;
static const float SHADOW_RANGE    = 100.0f;

} // namespace anonymous

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
    // projection matrix
    float aspectRatio =
        renderSettings.getResolution().x / renderSettings.getResolution().y;
    // perspective camera
    if ( m_mode == cam::PERSPECTIVE )
    {
        m_projectionMatrix =
            glm::perspective(
                m_fov * util::math::DEGREES_TO_RADIANS,
                aspectRatio,
                m_nearClip,
                m_farClip
            );
    }
    // orthographic camera
    else if ( m_mode == cam::ORTHOGRAPHIC )
    {
        m_projectionMatrix = glm::ortho(
                -aspectRatio, aspectRatio, -1.0f, 1.0f, m_nearClip, m_farClip );
    }
    // shadow camera
    else
    {
        // TODO: smaller size??
        // TODO: clipping? -farClip to farClip?
        // set up projection matrix
        m_projectionMatrix = glm::ortho(
            -SHADOW_CAM_SIZE,
             SHADOW_CAM_SIZE,
            -SHADOW_CAM_SIZE,
             SHADOW_CAM_SIZE,
            -SHADOW_RANGE,
             SHADOW_RANGE );
        // set up view matrix
        m_viewMatrix = glm::lookAt(
            m_transform->translation,
            glm::vec3( 0, 0, 0 ),
            glm::vec3( 0, 1, 0 )
        );
        // don't continue processing
        return;
    }

    // view matrix
    m_viewMatrix = glm::lookAt(
        glm::vec3( 0, 0, m_nearClip ),
        glm::vec3( 0, 0, 0 ),
        glm::vec3( 0, 1, 0 )
    );

    // don't transform if no tranform has been given
    if ( m_transform == NULL )
    {
        return;
    }

    // get the computed transformations
    glm::vec3 translation( m_transform->computeTranslation() );
    glm::vec3 rotation(m_transform->computeRotation());
    glm::vec3 scale(m_transform->computeScale());

    // scale
    m_viewMatrix *= glm::scale( scale );
    // rotation
    m_viewMatrix *= glm::rotate(
        -rotation.x * util::math::DEGREES_TO_RADIANS,
        glm::vec3( 1.0f, 0.0f, 0.0f )
    );
    m_viewMatrix *= glm::rotate(
        -rotation.y * util::math::DEGREES_TO_RADIANS,
        glm::vec3( 0.0f, 1.0f, 0.0f )
    );
    m_viewMatrix *= glm::rotate(
        -rotation.z * util::math::DEGREES_TO_RADIANS,
        glm::vec3( 0.0f, 0.0f, 1.0f )
    );
    // translation
    m_viewMatrix *= glm::translate( -translation );
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

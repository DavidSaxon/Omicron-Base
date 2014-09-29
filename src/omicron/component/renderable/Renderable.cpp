#include "Renderable.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Renderable::Renderable(
        const std::string& id,
              int          layer,
              Transform*   transform,
        const Material     material )
    :
    Component  ( id ),
    visible    ( true ),
    m_layer    ( layer ),
    m_transform( transform ),
    m_material ( material )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

component::Type Renderable::getType() const
{
    return component::RENDERABLE;
}

int Renderable::getLayer() const
{
    return m_layer;
}

Transform* Renderable::getTransform()
{
    return m_transform;
}

Material& Renderable::getMaterial()
{
    return m_material;
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Renderable::applyTransformations( Camera* camera )
{
    // do nothing if the transform is null
    if ( !m_transform )
    {
        return;
    }

    // TODO REMOVE ME
    //----------------------------------------------------------------------
    // apply translation
    glm::vec3 translation( m_transform->computeTranslation() );
    glTranslatef( translation.x, translation.y, translation.z );

    // TODO: local and global shit
    // apply rotation
    glm::vec3 rotation( m_transform->computeRotation() );
    glRotatef( rotation.x, 1.0f, 0.0f, 0.0f );
    glRotatef( rotation.y, 0.0f, 1.0f, 0.0f );
    glRotatef( rotation.z, 0.0f, 0.0f, 1.0f );

    // apply scale
    glm::vec3 scale( m_transform->computeScale() );
    glScalef( scale.x, scale.y, scale.z );
    //----------------------------------------------------------------------

    // TODO: REMOVE BRACES
    {
    m_modelMatrix = glm::mat4( 1.0f );
    glm::vec3 translation( m_transform->computeTranslation() );
    m_modelMatrix *= glm::translate( translation );
    glm::vec3 rotation( m_transform->computeRotation() );
    m_modelMatrix *= glm::rotate( rotation.x, glm::vec3( 1.0f, 0.0f, 0.0f ) );
    m_modelMatrix *= glm::rotate( rotation.y, glm::vec3( 0.0f, 1.0f, 0.0f ) );
    m_modelMatrix *= glm::rotate( rotation.z, glm::vec3( 0.0f, 0.0f, 1.0f ) );
    glm::vec3 scale( m_transform->computeScale() );
    m_modelMatrix *= glm::scale( scale );
    //calculate the model, view, projection matrix
    m_modelViewProjectionMatrix =
        camera->getProjectionMatrix() *
        camera->getViewMatrix() *
        m_modelMatrix;
    }
}

void Renderable::setShader()
{
    // get the OpenGL program
    GLuint program = m_material.shader.getProgram();
    // use the shader
    glUseProgram( program );

    // pass in the matrices to the shader
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelViewProjectionMatrix" ),
        1, GL_FALSE, &m_modelViewProjectionMatrix[0][0] );

    // pass in colour to the shader
    glUniform4f(
        glGetUniformLocation( program, "u_colour" ),
        m_material.colour.r,
        m_material.colour.g,
        m_material.colour.b,
        m_material.colour.a
    );

    // texture
    if ( m_material.texture != NULL )
    {
        glUniform1i( glGetUniformLocation( program, "u_hasTexture" ), 1 );
        glBindTexture( GL_TEXTURE_2D, m_material.texture->getId() );
    }
    else
    {
        glUniform1i( glGetUniformLocation( program, "u_hasTexture" ), 0 );
        glBindTexture( GL_TEXTURE_2D, 0 );
    }

    // lighting
    if ( m_material.isShadeless() )
    {
        // material is not affected by light
        glUniform1i( glGetUniformLocation( program, "u_shadeless" ), 1 );
    }
    else
    {
        // material is affected by light
        glUniform1i( glGetUniformLocation( program, "u_shadeless" ), 0 );

        // pass in ambient light
        glm::vec3 ambientLight =
            renderSettings.getAmbientColour() *
            renderSettings.getAmbientStrength();
        glUniform3f(
            glGetUniformLocation( program, "u_ambientLight" ),
            ambientLight.r, ambientLight.g, ambientLight.b
        );

        // pass in directional lights
        // TODO:

        // pass in point lights
        // TODO:

        // pass in spot lights
        // TODO:
    }
}

void Renderable::unsetShader()
{
    glUseProgram( 0 );
    glBindTexture( GL_TEXTURE_2D, 0 );
}

} // namespace omi

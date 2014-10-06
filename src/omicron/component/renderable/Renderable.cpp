#include "Renderable.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

Shader Renderable::selectionShader;

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
    selectable ( false ),
    selected   ( false ),
    m_layer    ( layer ),
    m_transform( transform ),
    m_material ( material )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Renderable::render( Camera* camera )
{
    // update the material
    m_material.update();

    // only render if the sprite is visible and the camera there is a camera
    if ( !visible || !m_material.isVisible() || camera == NULL)
    {
        return;
    }

    applyTransformations( camera );
    setShader();
    draw();
    unsetShader();
}

void Renderable::renderSelectable(
        Camera* camera,
        unsigned char red,
        unsigned char green,
        unsigned char blue )
{
    // don't bother rendering if there is no camera
    if ( camera == NULL )
    {

        return;
    }

    //set up
    applyTransformations( camera );

    // shader shit
    GLuint program = selectionShader.getProgram();
    glUseProgram( program );
    // matrix
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelViewProjectionMatrix" ),
        1, GL_FALSE, &m_modelViewProjectionMatrix[0][0] );
    // colour
    glUniform4f(
        glGetUniformLocation( program, "u_colour" ),
        static_cast<float>( red )   / 255.0f,
        static_cast<float>( green ) / 255.0f,
        static_cast<float>( blue )  / 255.0f,
        1.0f
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

    // draw
    draw();

    // clean up
    glUseProgram( 0 );
    glBindTexture( GL_TEXTURE_2D, 0 );
}

//-----------------------------------GETTERS------------------------------------

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

//-----------------------------------SETTERS------------------------------------

void Renderable::setLayer( int layer )
{
    m_layer = layer;
}

void Renderable::setTransform( Transform* transform )
{
    m_transform = transform;
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

    // get the computed transformations
    glm::vec3 translation( m_transform->computeTranslation() );
    glm::vec3 rotation( m_transform->computeRotation() );
    glm::vec3 scale( m_transform->computeScale() );

    // apply to matrices
    m_modelMatrix = glm::mat4( 1.0f );
    m_modelMatrix *= glm::translate( translation );
    m_modelMatrix *= glm::rotate( rotation.x, glm::vec3( 1.0f, 0.0f, 0.0f ) );
    m_modelMatrix *= glm::rotate( rotation.y, glm::vec3( 0.0f, 1.0f, 0.0f ) );
    m_modelMatrix *= glm::rotate( rotation.z, glm::vec3( 0.0f, 0.0f, 1.0f ) );
    m_modelMatrix *= glm::scale( scale );

    //calculate the model, view, projection matrix
    m_modelViewProjectionMatrix =
        camera->getProjectionMatrix() *
        camera->getViewMatrix() *
        m_modelMatrix;
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

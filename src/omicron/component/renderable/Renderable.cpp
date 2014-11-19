#include "Renderable.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

Shader Renderable::glowShader;
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

void Renderable::render( Camera* camera, const LightData& lightData )
{
    // TODO: this might need to be done elsewhere since glow passes will be
    // behind
    // update the material
    m_material.update();

    // only render if visible and there is a camera
    if ( !visible || !m_material.isVisible() || camera == NULL)
    {
        return;
    }

    applyTransformations();

    calculateMatrices( camera );
    setShader( lightData );
    draw();
    unsetShader();
}

void Renderable::renderGlow( Camera* camera )
{
    // only render if visible and there is a camera
    if ( !visible || !m_material.isVisible() || camera == NULL)
    {
        return;
    }

    applyTransformations();
    calculateMatrices( camera );

    // get the OpenGL program
    GLuint program = glowShader.getProgram();
    // use the shader
    glUseProgram( program );

    // pass in the matrices to the shader
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelViewProjectionMatrix" ),
        1, GL_FALSE, &m_modelViewProjectionMatrix[0][0] );

    // get the colour based on glow component
    glm::vec3 colour( 0.0f, 0.0f, 0.0f );
    float brightness = 1.0f;
    if ( m_material.glow != NULL )
    {
        colour     = m_material.glow->getColour();
        brightness = m_material.glow->getBrightness();
    }

    // pass in colour to the shader
    glUniform4f(
        glGetUniformLocation( program, "u_colour" ),
        colour.r,
        colour.g,
        colour.b,
        brightness
    );

    // draw
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
    applyTransformations();
    calculateMatrices( camera );

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

void Renderable::applyTransformations()
{
    // apply identity to model matrix
    m_modelMatrix = glm::mat4( 1.0f );

    // do nothing if the transform is null
    if ( !m_transform )
    {
        return;
    }

    // get the computed transformations
    glm::vec3 translation( m_transform->computeTranslation() );
    glm::vec3 rotation( m_transform->computeRotation() );
    rotation.x *= util::math::DEGREES_TO_RADIANS;
    rotation.y *= util::math::DEGREES_TO_RADIANS;
    rotation.z *= util::math::DEGREES_TO_RADIANS;
    glm::vec3 scale( m_transform->computeScale() );

    // apply to matrices
    m_modelMatrix *= glm::translate( translation );
    m_modelMatrix *= glm::rotate( rotation.x, glm::vec3( 1.0f, 0.0f, 0.0f ) );
    m_modelMatrix *= glm::rotate( rotation.y, glm::vec3( 0.0f, 1.0f, 0.0f ) );
    m_modelMatrix *= glm::rotate( rotation.z, glm::vec3( 0.0f, 0.0f, 1.0f ) );
    m_modelMatrix *= glm::scale( scale );
}

void Renderable::calculateMatrices( Camera* camera )
{
    // get the view matrix from the camera
    m_viewMatrix = camera->getViewMatrix();
    // calculate the model, view matrix
    m_modelViewMatrix = camera->getViewMatrix() * m_modelMatrix;
    // calcaulate the normal matrix
    m_normalMatrix = glm::mat3( glm::transpose( glm::inverse( m_modelViewMatrix ) ) );
    //calculate the model, view, projection matrix
    m_modelViewProjectionMatrix =
        camera->getProjectionMatrix() *
        camera->getViewMatrix() *
        m_modelMatrix;
}

void Renderable::setShader( const LightData& lightData )
{
    // get the OpenGL program
    GLuint program = m_material.shader.getProgram();
    // use the shader
    glUseProgram( program );

    // pass in the matrices to the shader
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelMatrix" ),
        1, GL_FALSE, &m_modelMatrix[0][0] );
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_viewMatrix" ),
        1, GL_FALSE, &m_viewMatrix[0][0] );
    glUniformMatrix4fv(
        glGetUniformLocation( program, "u_modelViewMatrix" ),
        1, GL_FALSE, &m_modelViewMatrix[0][0] );
    glUniformMatrix3fv(
        glGetUniformLocation( program, "u_normalMatrix" ),
        1, GL_FALSE, &m_normalMatrix[0][0] );
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

        // the number of lights
        glUniform1i(
            glGetUniformLocation( program, "u_lightCount" ),
            lightData.types.size()
        );
        if ( lightData.types.size() > 0 )
        {
            // the types of lights
            glUniform1iv(
                glGetUniformLocation( program, "u_lightType" ),
                lightData.types.size(),
                &lightData.types[0]
            );
            // the positions of lights
            glUniform3fv(
                glGetUniformLocation( program, "u_lightPos" ),
                lightData.types.size(),
                &lightData.positions[0]
            );
            // the rotations of lights
            glUniform3fv(
                glGetUniformLocation( program, "u_lightRot" ),
                lightData.types.size(),
                &lightData.rotations[0]
            );
            // the colours of lights
            glUniform3fv(
                glGetUniformLocation( program, "u_lightColour" ),
                lightData.types.size(),
                &lightData.colours[0]
            );
            // the attenuation of lights
            glUniform3fv(
                glGetUniformLocation( program, "u_lightAttenuation" ),
                lightData.types.size(),
                &lightData.attenuations[0]
            );
            // the arcs of lights
            glUniform2fv(
                glGetUniformLocation( program, "u_lightArc" ),
                lightData.types.size(),
                &lightData.arcs[0]
            );
        }
    }

    //--------------------------------PROPERTIES--------------------------------

    // specular property
    Specular* specular = m_material.specular;
    float shininess = 0.0f;
    glm::vec3 specularColour;
    if ( specular != NULL )
    {
        shininess = specular->getShininess();
        specularColour = specular->getColour();
    }
    glUniform1f(
        glGetUniformLocation( program, "u_shininess" ),
        shininess
    );
    glUniform3f(
        glGetUniformLocation( program, "u_specularColour" ),
        specularColour.r,
        specularColour.g,
        specularColour.b
    );
}

void Renderable::unsetShader()
{
    glUseProgram( 0 );
    glBindTexture( GL_TEXTURE_2D, 0 );
}

} // namespace omi

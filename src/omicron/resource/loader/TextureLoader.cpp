#include "Loaders.hpp"

namespace omi {

namespace loader {

Texture textureFromImage(const std::string& filePath) {


    //--------------------------LOAD IMAGE USING DEVIL--------------------------


    // the id of the image we are loading
    ILuint imageId;

    // generate and bind the image
    ilGenImages(1, &imageId);
    ilBindImage(imageId);

    // match the image origin to OpenGL's
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

    //load the image
    ILboolean success = ilLoadImage((ILstring)filePath.c_str());

    // check that the image loaded successfully
    if(!success) {

        std::cout << "image load failed" << std::endl;

        // unrecognised format??

        //clean up
        ilBindImage(0);
        ilDeleteImages(1, &imageId);
        // TODO: freak out
    }

    // check that the image actually contains some data
    void* data = ilGetData();
    if (!data) {

        std::cout << "empty data! FUCK!" << std::endl;

        ilBindImage(0);
        ilDeleteImages(1, &imageId);
        // TODO: freak out
    }

    //get the important parameters from the image
    int width  = ilGetInteger(IL_IMAGE_WIDTH);
    int height = ilGetInteger(IL_IMAGE_HEIGHT);
    int type   = ilGetInteger(IL_IMAGE_TYPE);
    int format = ilGetInteger(IL_IMAGE_FORMAT);


    //--------------------------CREATE OPENGL TEXTURE---------------------------


    // the id of the texture in OpenGL
    GLuint textureId;

    // generate and bind the texture
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // set the pixel store parameters
    glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
    glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // load the texture into OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, format, width,
                 height, 0, format, type, data);

    // set the filtering modes
    glTexParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // generate mipmaps
    glGenerateMipmap(GL_TEXTURE_2D);


    //--------------------CREATE AND RETURN OMICRON TEXTURE---------------------


    return Texture(textureId, util::vec::Vector2(width, height));
}

} // namespace loader

} // namespace omi

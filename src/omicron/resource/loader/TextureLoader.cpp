#include "Loaders.hpp"

namespace omi {

namespace loader {

Texture* textureFromImage(const std::string& filePath) {

    // the id of the image we are loading
    ILuint imageId;

    // generate the image name
    ilGenImages(1, &imageId);
    // bind it
    ilBindImage(imageId);
    // match the image origin to OpenGL's
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

    //load the image
    ILboolean success = ilLoadImage((ILstring)filePath.c_str());

    // check that the image loaded successfully
    if(!success) {

        std::cout << "image load failed" << std::endl;

        //clean up
        ilBindImage(0);
        ilDeleteImages(1, &imageId);
        // TODO: freak out
    }

    // check that the image actually contains some data
    void* data = ilGetData();
    if (!data) {

        ilBindImage(0);
        ilDeleteImages(1, &imageId);
        // TODO: freak out
    }

    //get the important parameters from the image
    util::vec::Vector2 dimesions(
            static_cast<float>(ilGetInteger(IL_IMAGE_WIDTH)),
            static_cast<float>(ilGetInteger(IL_IMAGE_HEIGHT)));
    int type   = ilGetInteger(IL_IMAGE_TYPE);
    int format = ilGetInteger(IL_IMAGE_FORMAT);

    return new Texture();
}

} // namespace loader

} // namespace omi

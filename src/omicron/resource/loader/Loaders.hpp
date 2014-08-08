#ifndef OMICRON_RESOURCE_LOADER_LOADERS_H_
#   define OMICRON_RESOURCE_LOADER_LOADERS_H_

#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <IL/il.h>

#include "lib/Utilitron/StringUtil.hpp"
#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/rendering/object_data/Geometry.hpp"
#include "src/omicron/rendering/shading/Texture.hpp"

namespace omi {

/***********************************************\
| Functions used for loading data into Omicron. |
\***********************************************/
namespace loader {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

//-------------------------------TEXTURE LOADERS--------------------------------

/** Loads a texture from an image file
@param filePath the path to the image
@return the loaded texture */
Texture textureFromImage(const std::string& filePath);

//-------------------------------GEOMETRY LOADERS-------------------------------

/** Loads geometry data from a wavefront file
@param filePath the path to the file to load the data from
@return the loaded geometry data */
Geometry* geoFromWavefront(const std::string& filePath);

} // namespace loader

} // namespace omi

#endif

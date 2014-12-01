#include "Loaders.hpp"

namespace omi {

namespace loader {

Font* loadFontFromFile(
    FT_Library* freeType,
    const std::string& filePath )
{
    Font* font = new Font();

    if( int result = FT_New_Face( *freeType, filePath.c_str(), 0, font ) )
    {
        // TODO: throw exception
        std::cout << "failed to load font: " << result << std::endl;
    }
    FT_Set_Pixel_Sizes( *font, 0, 14 );

    return font;
}

} // namespace loader

} // namespace omi

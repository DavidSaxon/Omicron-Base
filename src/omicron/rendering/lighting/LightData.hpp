#ifndef OMICRON_RENDERING_LIGHTING_LIGHTDATA_HPP_
#   define OMICRON_RENDERING_LIGHTING_LIGHTDATA_HPP_

#include <vector>

namespace omi {

/*****************************************************\
| Structure that contains packed data for all lights. |
\*****************************************************/
struct LightData {
    // the light type
    std::vector<int> types;
    // the positions of the lights in eye space
    std::vector<float> positions;
    // the rotations of the lights
    std::vector<float> rotations;
    // the colour of the lights
    std::vector<float> colours;
    // the attenuation of the lights
    std::vector<float> attenuations;
    // the arcs of the lights
    std::vector<float> arcs;
};

} // namespace omi

#endif

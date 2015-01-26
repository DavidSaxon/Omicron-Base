#include "KeyFrameMeshResource.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

KeyFrameMeshResource::KeyFrameMeshResource(
        resource_group::ResourceGroup resourceGroup,
        int                           layer,
        const std::string&            material,
        const std::string&            filePath ) :
    Resource  ( resourceGroup ),
    m_layer   ( layer ),
    m_material( material ),
    m_filePath( filePath )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KeyFrameMeshResource::load()
{
    if ( !m_loaded )
    {
        loader::geoFromKeyFrameWavefront( m_filePath, m_geoMap );
        m_loaded = true;
    }
}

void KeyFrameMeshResource::release()
{
    // TODO:
}

KeyFrameMesh* KeyFrameMeshResource::get(
        const std::string& id, Transform* transform ) const
{
    if (!m_loaded) {

        std::cout << "attempted to get unloaded key frame mesh" << std::endl;
        //TODO: throw an exception
    }

    return new KeyFrameMesh(
        id, m_layer, transform, m_geoMap,
        ResourceManager::getMaterial(m_material)
    );
}

} // namespace omi

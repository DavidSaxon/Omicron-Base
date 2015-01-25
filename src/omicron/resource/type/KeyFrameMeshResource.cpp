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
    Resource( resourceGroup ),
    m_filePath( filePath )
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void KeyFrameMeshResource::load()
{
    std::cout << "Key Frame Mesh LOAD!" << std::endl;
}

void KeyFrameMeshResource::release()
{
}

KeyFrameMesh* KeyFrameMeshResource::get( const std::string& id, Transform* transform ) const
{
}

} // namespace omi

#include "ResourceServer.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

bool ResourceServer::m_loadFromLibrary = true;

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void ResourceServer::init()
{
    // TODO: read in the header if we're loading from the library
}

void ResourceServer::loadFromLibrary( bool state )
{
    m_loadFromLibrary = state;
}

void ResourceServer::get( const std::string& path, VirtualFile& file )
{
    if ( m_loadFromLibrary )
    {
        // TODO:
    }
    else
    {
        readFromDisk( path, file );
    }
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void ResourceServer::readFromDisk( const std::string& path, VirtualFile& file )
{
    FILE* f = fopen( path.c_str(), "rb" );
    if ( f == NULL )
    {
        std::cout << "Resource server failed to open literal file: "
                  << path << std::endl;
        // TODO: throw an exception
        return;
    }

    // get the size of the file
    fseek( f, 0, SEEK_END );
    long size = ftell( f );
    rewind( f );

    // allocate a char array to store the file data in
    char* buffer = ( char* ) malloc( sizeof( char ) * ( size + 1 ) );
    if ( buffer == NULL )
    {
        std::cout << "Resource server failed to allocate memory for file "
                  << "contents" << std::endl;
        // TODO: throw an exception
        return;
    }

    // copy the file into the buffer
    size_t result = fread( buffer, 1, size, f );
    if ( result != size )
    {
        std::cout << "Resource failed to read file contents into buffer."
                  << std::endl;
        delete buffer;
        // TODO: throw an exception
        return;
    }
    // make sure it's null terminated
    buffer[ size ] = '\0';

    // close the file
    fclose( f );

    // pass on to the virtual file
    file.setData( buffer );
}

} // namespace omi

#include "VirtualFile.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

VirtualFile::VirtualFile()
    :
    m_data  ( NULL ),
    m_cursor( 0 )
{
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

VirtualFile::~VirtualFile()
{
    // delete the date contained within this file
    delete m_data;
    m_data = NULL;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void VirtualFile::setData( char* data )
{
    m_data = data;
    m_cursor = 0;
}

char* VirtualFile::getData()
{
    return m_data;
}

void VirtualFile::rewind()
{
    m_cursor = 0;
}

bool VirtualFile::hasNextLine()
{
    // TODO:
    return true;
}

void VirtualFile::nextLine( std::string& line )
{
    // TODO:
}

} // namespace omi

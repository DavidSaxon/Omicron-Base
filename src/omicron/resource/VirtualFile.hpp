#ifndef OMICRON_RESOURCE_VIRTUALFILE_HPP_
#   define OMICRON_RESOURCE_VIRTUALFILE_HPP_

#include <string>

#include "lib/Utilitron/MacroUtil.hpp"

namespace omi {

/**************************************************************************\
| Virtual files are wrappers around the contents of a file that are loaded |
| into memory.                                                             |
\**************************************************************************/
class VirtualFile {
private:

    DISALLOW_COPY_AND_ASSIGN( VirtualFile );

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new virtual file that currently holds no data */
    VirtualFile();

    //--------------------------------------------------------------------------
    //                                 DESTURCTOR
    //--------------------------------------------------------------------------

    ~VirtualFile();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Sets the data of the virtual file and sets the cursor at index 0 */
    void setData( char* data );

    /** @returns the data of the file */
    char* getData();

    /** Resets the cursor to the start of the file */
    void rewind();

    /** @return if there is a another line in the file to read */
    bool hasNextLine();

    /** @return the next line from the file */
    void nextLine( std::string& line );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the data of the file
    char* m_data;
    // the current cursor position
    unsigned m_cursor;

    // // if the first line has been found
    // bool m_foundFirstLine;
    // // the next line in the file
    // std::string
};

} // namespace omi

#endif

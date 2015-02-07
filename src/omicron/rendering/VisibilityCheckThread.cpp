#include "VisibilityCheckThread.hpp"

namespace omi {

namespace vis_check {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

bool ready = true;
bool sort = false;
std::vector<GLubyte>* buffer = NULL;
std::set<unsigned> visibleSet;

void sortVisible()
{
    while ( true )
    {
        if ( sort )
        {
            ready = false;
            sort = false;
            visibleSet.clear();
            if ( buffer == NULL )
            {
                ready = true;
                return;
            }

            for ( unsigned i = 0; i < buffer->size(); ++i )
            {
                // build the colour key
                unsigned colour =  static_cast<unsigned>( ( *buffer )[ i ] );
                colour |= static_cast<unsigned>( ( *buffer )[ i + 1 ] ) << 8;
                colour |= static_cast<unsigned>( ( *buffer )[ i + 2] ) << 16;

                // add to the set of colours
                visibleSet.insert( colour );
            }

            ready = true;
        }
        else
        {
            util::time::sleep( 5 );
        }
    }
}

} // namespace vis_check

} // namespace omi

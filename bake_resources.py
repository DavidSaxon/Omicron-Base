#!/usr/bin/env python

import os

# open the resource header directory
with open( 'resources.omi_h', 'w' ) as lib_header:
    # open the resource library file
    with open( 'resources.omi_lib', 'w' ) as lib_file:
        # find all the files in the resource directory
        for root, _, filenames in os.walk( 'res/' ):
            for filename in filenames:
                filename = os.path.join( root, filename )
                with open( filename ) as f:
                    # add the file path and location to the header
                    lib_header.write(
                            str( lib_file.tell() ) + ' ' + filename + '\n'
                    )
                    # write the file to library
                    lib_file.write( f.read() )
                    lib_file.write( '\n' )

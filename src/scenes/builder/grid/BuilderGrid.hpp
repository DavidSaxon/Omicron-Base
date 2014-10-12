#ifndef VOIDWALKER_SCENES_BUILDER_GRID_BUILDERGRID_HPP_
#   define VOIDWALKER_SCENES_BUILDER_GRID_BUILDERGRID_HPP_

#include <map>
#include <sstream>

#include "lib/Utilitron/MathUtil.hpp"

#include "src/entities/ship/Block.hpp"
#include "src/override/Values.hpp"

/**************************************************************\
| A collection that stores the layout of blocks in a 1x1 grid. |
\**************************************************************/
class BuilderGrid {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    BuilderGrid();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** @return the block at the given position */
    Block* get( float x, float y );

    /** @return the block in the direction from the given position */
    Block* get( float x, float y, connection::Direction direction );

    /** Gets the min and max distances of the grid */
    void getSize( float& minX, float& maxX, float& minY, float& maxY );

    /** Sets the block at the given position
    @param x the x position to place the block at
    @param y the y position to place the block at
    @param block the block to add to the grid */
    void set( float x, float y, Block* block );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the map which contains cell indices to blocks
    std::map<std::string, Block*> m_grid;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Converts a given x and y value to stringified grid key
    @param x the x value to use in the grid key
    @param y the y value to use in the grid key
    @return the grid key */
    std::string posToKey( float x, float y ) const;

    /** Converts the given key to x and y floating point numbers
    @param key the key to convert
    @param x the converted x value
    @param y the converted y value */
    void keyToPos( const std::string& key, float& x, float& y );
};

#endif

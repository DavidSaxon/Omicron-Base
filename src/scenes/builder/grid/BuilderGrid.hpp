#ifndef VOIDWALKER_SCENES_BUILDER_GRID_BUILDERGRID_HPP_
#   define VOIDWALKER_SCENES_BUILDER_GRID_BUILDERGRID_HPP_

#include <map>

#include "src/entities/ship/Block.hpp"

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

    /** Sets the block at the given position
    @param x the x position to place the block at
    @param y the y position to place the block at
    @param block the block to add to the grid */
    Block* set( float x, float y, Block* block );

    // TODO: neighbours

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
};

#endif

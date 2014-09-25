#ifndef VOIDWALKER_SHIP_BLOCKFACTORY_HPP_
    #define VOIDWALKER_SHIP_BLOCKFACTORY_HPP_

#include "src/entities/ship/Block.hpp"
// draw components
#include "src/entities/ship/draw_component/RandomStillDrawComp.hpp"

/**********************************************************\
| function for building and returning all ship block types |
\**********************************************************/
namespace block_factory {

//------------------------------------------------------------------------------
//                                     HULLS
//------------------------------------------------------------------------------

inline Block* hullSteel( const util::vec::Vector3& pos )
{
    Block* block = new Block( util::vec::Vector3( ) );
    block->drawComponent = new RandomStillDrawComp( "ship_hull_steel" );

    return block;
}

} // namespace block_factory

#endif

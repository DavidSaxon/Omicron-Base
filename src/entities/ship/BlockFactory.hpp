#ifndef VOIDWALKER_SHIP_BLOCKFACTORY_HPP_
    #define VOIDWALKER_SHIP_BLOCKFACTORY_HPP_

#include "src/entities/ship/Block.hpp"
// draw components
#include "src/entities/ship/draw_component/RandomStillDrawComp.hpp"
#include "src/entities/ship/draw_component/SpriteDrawComp.hpp"

/**********************************************************\
| function for building and returning all ship block types |
\**********************************************************/
namespace block_factory {

//------------------------------------------------------------------------------
//                                     HULLS
//------------------------------------------------------------------------------

inline Block* hullSteel( const glm::vec3& pos )
{
    Block* block = new Block( pos );
    block->drawComponent = new RandomStillDrawComp( "ship_hull_steel" );

    return block;
}

//------------------------------------------------------------------------------
//                                    WEAPONS
//------------------------------------------------------------------------------

inline Block* weaponRocketLauncher( const glm::vec3& pos )
{
    Block* block = new Block( pos );
    block->drawComponent = new SpriteDrawComp( "ship_weapon_rocket_launcher" );

    return block;
}

//------------------------------------------------------------------------------
//                                    ENGINES
//------------------------------------------------------------------------------

inline Block* engineCoal( const glm::vec3& pos )
{
    Block* block = new Block( pos );
    block->drawComponent = new SpriteDrawComp( "ship_engine_coal" );

    return block;
}

} // namespace block_factory

#endif

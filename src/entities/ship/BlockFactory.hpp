#ifndef VOIDWALKER_SHIP_BLOCKFACTORY_HPP_
    #define VOIDWALKER_SHIP_BLOCKFACTORY_HPP_

#include "src/entities/ship/Block.hpp"
#include "src/entities/ship/connection_component/ConnectionComponent.hpp"
#include "src/entities/ship/draw_component/RandomStillDrawComp.hpp"
#include "src/entities/ship/draw_component/SpriteDrawComp.hpp"

/**********************************************************\
| function for building and returning all ship block types |
\**********************************************************/
namespace block_factory {

namespace {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

static const unsigned DEFAULT_HULL_CONNECTIONS =
        connection::TOP    |
        connection::BOTTOM |
        connection::LEFT   |
        connection::RIGHT  |
        connection::ABOVE;
static const unsigned DEFAULT_WEAPON_CONNECTIONS =
        connection::BOTTOM |
        connection::ABOVE;
static const unsigned DEFAULT_ENGINE_CONNECTIONS =
        connection::TOP |
        connection::ABOVE;

} // namespace anonymous

//------------------------------------------------------------------------------
//                                     HULLS
//------------------------------------------------------------------------------

inline Block* hullSteel( const glm::vec3& pos )
{
    Block* block = new Block( pos );
    block->drawComponent = new RandomStillDrawComp( "ship_hull_steel" );
    block->connectionComponent =
        new ConnectionComponent( DEFAULT_HULL_CONNECTIONS );

    return block;
}

//------------------------------------------------------------------------------
//                                    WEAPONS
//------------------------------------------------------------------------------

inline Block* weaponRocketLauncher( const glm::vec3& pos )
{
    Block* block = new Block( pos );
    block->drawComponent = new SpriteDrawComp( "ship_weapon_rocket_launcher" );
    block->connectionComponent =
        new ConnectionComponent( DEFAULT_WEAPON_CONNECTIONS );

    return block;
}

//------------------------------------------------------------------------------
//                                    ENGINES
//------------------------------------------------------------------------------

inline Block* engineCoal( const glm::vec3& pos )
{
    Block* block = new Block( pos );
    block->drawComponent = new SpriteDrawComp( "ship_engine_coal" );
    block->connectionComponent =
        new ConnectionComponent( DEFAULT_ENGINE_CONNECTIONS );

    return block;
}

} // namespace block_factory

#endif

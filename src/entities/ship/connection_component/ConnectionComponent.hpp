#ifndef VOIDWALKER_SHIP_CONNECTIONCOMPONENT_HPP_
#   define VOIDWALKER_SHIP_CONNECTIONCOMPONENT_HPP_

#include "src/omicron/entity/Entity.hpp"

class Block;
#include "src/entities/ship/Block.hpp"

namespace connection {

enum Direction {
    TOP    = 1,
    BOTTOM = 2,
    LEFT   = 4,
    RIGHT  = 8,
    ABOVE  = 16
};

} // namespace connection

class ConnectionComponent {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new connection component
    @param directions the direction the component can connect in */
    ConnectionComponent( unsigned directions );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** @return the directions the component can connection with */
    unsigned getDirections() const;

    /** @return if the given direction is available to connect with
    @param direction the direction to check
    @return if the given direction is available */
    bool isAvailable( connection::Direction direction );

    /** get the block connected in the given direction
    @param direction the direction to get the block from
    @return the block in the given direction, or NULL if it doesn't exists */
    Block* getBlock( connection::Direction direction );

    /** Sets the connected block in the given direction
    @param direction the direction to connect the block in
    @param block the block to connect */
    void connect( connection::Direction direction, Block* block );

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the directions the block can connect in
    unsigned m_directions;
    // the neighboring blocks
    Block* m_top;
    Block* m_bottom;
    Block* m_left;
    Block* m_right;
    Block* m_above;
};

#endif

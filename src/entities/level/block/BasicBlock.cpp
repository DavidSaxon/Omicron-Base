#include "BasicBlock.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BasicBlock::BasicBlock(const std::string& spriteName, const std::string& weapon,
        const std::string& engine, const std::string& trail,
        const util::vec::Vector3& pos, block::Owner owner) :
    Block(spriteName, weapon, engine, trail, pos, owner) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

BasicBlock::~BasicBlock() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------
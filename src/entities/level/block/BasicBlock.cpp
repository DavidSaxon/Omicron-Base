#include "BasicBlock.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

BasicBlock::BasicBlock(const std::string& spriteName,
    const util::vec::Vector3& pos, block::Owner owner) :
    Block(spriteName, pos, owner) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

BasicBlock::~BasicBlock() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void BasicBlock::init() {

    // super call
    Block::init();
}

void BasicBlock::update() {

    // super call
    Block::update();
}


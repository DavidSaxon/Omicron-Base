#ifndef BOF_LEVEL_BLOCK_BASICBLOCK_H_
#    define BOF_LEVEL_BLOCK_BASICBLOCK_H_

#include "Block.hpp"

class BasicBlock : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    BasicBlock(const std::string& sprite_name, const std::string& weapon,
        const std::string& engine, const std::string& trail,
        const util::vec::Vector3& pos, block::Owner owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~BasicBlock();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

};

#endif

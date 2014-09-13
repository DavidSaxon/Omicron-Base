#ifndef BOF_LEVEL_BLOCK_STEELBLOCK_H_
#    define BOF_LEVEL_BLOCK_STEELBLOCK_H_

#include "BasicBlock.hpp"

class SteelBlock : public BasicBlock {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    SteelBlock(const util::vec::Vector3& pos, block::Owner owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~SteelBlock();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------
};

#endif

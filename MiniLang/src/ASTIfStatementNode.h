//
// Created by sandro on 1/11/16.
//

#ifndef CPS2000_MINILANG_ASTIFSTATEMENTNODE_H
#define CPS2000_MINILANG_ASTIFSTATEMENTNODE_H

#include "ASTStatementNode.h"

class ASTIfStatementNode : ASTStatementNode {
public:
    ASTIfStatementNode();
    virtual ~ASTIfStatementNode();

    virtual void PrintInfo(int p_level) override;
};


#endif //CPS2000_MINILANG_ASTIFSTATEMENTNODE_H

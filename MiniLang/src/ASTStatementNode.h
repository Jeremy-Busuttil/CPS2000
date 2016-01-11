//
// Created by sandro on 1/11/16.
//

#ifndef CPS2000_MINILANG_ASTSTATEMENTNODE_H
#define CPS2000_MINILANG_ASTSTATEMENTNODE_H

#include "ASTNode.h"

class ASTStatementNode : public ASTNode {
public:
    ASTStatementNode();
    virtual ~ASTStatementNode();

    virtual void PrintInfo(int p_level) override;
};


#endif //CPS2000_MINILANG_ASTSTATEMENTNODE_H

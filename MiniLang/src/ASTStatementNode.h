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

    virtual void Accept(Visitor * v) = 0;
    virtual void PrintInfo(int p_level) = 0;
};


#endif //CPS2000_MINILANG_ASTSTATEMENTNODE_H

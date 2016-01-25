//
// Created by sandro on 1/11/16.
//

#ifndef CPS2000_MINILANG_ASTIFSTATEMENTNODE_H
#define CPS2000_MINILANG_ASTIFSTATEMENTNODE_H

#include "ASTStatementNode.h"
#include "ASTExprNode.h"

class ASTIfStatementNode : public ASTStatementNode {
public:
    ASTIfStatementNode();
    virtual ~ASTIfStatementNode();

    ASTExprNode * condition = nullptr;
    ASTNode * LHS = nullptr;
    ASTNode * RHS = nullptr;

    virtual void Accept(Visitor * v);
    virtual void PrintInfo(int p_level) override;
};


#endif //CPS2000_MINILANG_ASTIFSTATEMENTNODE_H

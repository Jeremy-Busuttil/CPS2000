//
// Created by sandro on 1/22/16.
//

#ifndef CPS2000_MINILANG_ASTRETURNSTATEMENTNODE_H
#define CPS2000_MINILANG_ASTRETURNSTATEMENTNODE_H

#include "ASTStatementNode.h"
#include "ASTExprNode.h"

class ASTReturnStatementNode : public ASTStatementNode{

public:
    ASTReturnStatementNode();
    virtual ~ASTReturnStatementNode();

    ASTExprNode * LHS = nullptr;

    virtual void Accept(Visitor * v);
    virtual void PrintInfo(int p_level) override;
};

#endif //CPS2000_MINILANG_ASTRETURNSTATEMENTNODE_H

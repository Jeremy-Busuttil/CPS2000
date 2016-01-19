//
// Created by sandro on 1/11/16.
//

#ifndef CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H
#define CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H

#include "ASTExprNode.h"
#include "ASTStatementNode.h"

class ASTAssignmentStatementNode : public ASTStatementNode {
public:
    ASTAssignmentStatementNode(const std::string &Name, ASTExprNode * p_RHS);
    virtual ~ASTAssignmentStatementNode();

    std::string LHS;
    ASTExprNode * RHS;

    virtual void Accept(Visitor * v) override;
    virtual void PrintInfo(int p_level) override;
};


#endif //CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H

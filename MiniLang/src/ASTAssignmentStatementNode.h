//
// Created by sandro on 1/11/16.
//

#ifndef CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H
#define CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H

#include "ASTExprNode.h"
#include "ASTStatementNode.h"

class ASTAssignmentStatementNode : ASTStatementNode {
public:
    ASTAssignmentStatementNode(const std::string &Name, std::unique_ptr<ASTExprNode> p_RHS);
    virtual ~ASTAssignmentStatementNode();

    std::string LHS;
    std::unique_ptr<ASTExprNode> RHS;

    virtual void PrintInfo(int p_level) override;
};


#endif //CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H

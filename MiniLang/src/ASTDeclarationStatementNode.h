//
// Created by sandro on 1/25/16.
//

#ifndef CPS2000_MINILANG_ASTDECLARATIONSTATEMENTNODE_H
#define CPS2000_MINILANG_ASTDECLARATIONSTATEMENTNODE_H

#include "ASTAssignmentStatementNode.h"
#include "ASTStatementNode.h"

class ASTDeclarationStatementNode : public ASTStatementNode {
public:
    ASTDeclarationStatementNode(const std::string &p_varType, ASTAssignmentStatementNode * p_RHS);
    virtual ~ASTDeclarationStatementNode();

    std::string varType;
    ASTAssignmentStatementNode * RHS;

    virtual void Accept(Visitor * v) override;
    virtual void PrintInfo(int p_level) override;
};


#endif //CPS2000_MINILANG_ASTDECLARATIONSTATEMENTNODE_H

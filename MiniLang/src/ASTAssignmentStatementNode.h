//
// Created by sandro on 1/11/16.
//

#ifndef CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H
#define CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H


#include "ASTStatementNode.h"

class ASTAssignmentStatementNode : ASTStatementNode {
public:
    ASTAssignmentStatementNode();
    virtual ~ASTAssignmentStatementNode();

    virtual void PrintInfo(int p_level) override;
};


#endif //CPS2000_MINILANG_ASTASSIGNMENTSTATEMENTNODE_H

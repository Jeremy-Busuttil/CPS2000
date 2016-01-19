//
// Created by sandro on 1/11/16.
//

#include "ASTAssignmentStatementNode.h"

ASTAssignmentStatementNode::ASTAssignmentStatementNode(const std::string &Name, ASTExprNode * p_RHS)
        : LHS(Name), RHS(p_RHS)
{

}

ASTAssignmentStatementNode::~ASTAssignmentStatementNode() {
    // TODO Auto-generated destructor stub
}

void ASTAssignmentStatementNode::PrintInfo(int p_level) {
    std::string tabs = "";
    for (int t = 0; t<p_level; t++) tabs.append("\t");
    std::cout << tabs << "ASTAssignmentStatementNode LHS, RHS" << std::endl;
}

void ASTAssignmentStatementNode::Accept(Visitor * v) {
    v->visit(this);
}
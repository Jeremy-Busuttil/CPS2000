//
// Created by sandro on 1/11/16.
//

#include "ASTAssignmentStatementNode.h"

ASTAssignmentStatementNode::ASTAssignmentStatementNode(const std::string &Name, std::unique_ptr<ASTExprNode> p_RHS)
        : LHS(Name), RHS(std::move(p_RHS))
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
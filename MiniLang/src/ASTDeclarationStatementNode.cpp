//
// Created by sandro on 1/25/16.
//

#include "ASTDeclarationStatementNode.h"

ASTDeclarationStatementNode::ASTDeclarationStatementNode(const std::string &p_varType, ASTAssignmentStatementNode * p_RHS)
        : varType(p_varType), RHS(p_RHS)
{

}

ASTDeclarationStatementNode::~ASTDeclarationStatementNode() {
    // TODO Auto-generated destructor stub
}

void ASTDeclarationStatementNode::PrintInfo(int p_level) {
    std::string tabs = "";
    for (int t = 0; t<p_level; t++) tabs.append("\t");
    std::cout << tabs << "ASTDeclarationStatementNode " << varType << std::endl;
}

void ASTDeclarationStatementNode::Accept(Visitor * v) {
    v->visit(this);
}
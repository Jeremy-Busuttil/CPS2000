//
// Created by sandro on 1/11/16.
//

#include "ASTIfStatementNode.h"

ASTIfStatementNode::ASTIfStatementNode() {
    // TODO Auto-generated constructor stub
}

ASTIfStatementNode::~ASTIfStatementNode() {
    // TODO Auto-generated destructor stub
}

void ASTIfStatementNode::PrintInfo(int p_level) {
    std::string tabs = "";
    for (int t = 0; t<p_level; t++) tabs.append("\t");
    std::cout << tabs << "ASTIfStatementNode C LHS RHS" << std::endl;
}

void ASTIfStatementNode::Accept(Visitor *v) {
    v->visit(this);
}
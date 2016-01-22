//
// Created by sandro on 1/22/16.
//

#include "ASTReturnStatementNode.h"

ASTReturnStatementNode::ASTReturnStatementNode() {
    // TODO Auto-generated constructor stub
}

ASTReturnStatementNode::~ASTReturnStatementNode() {
    // TODO Auto-generated destructor stub
}

void ASTReturnStatementNode::PrintInfo(int p_level) {
    std::string tabs = "";
    for (int t = 0; t<p_level; t++) tabs.append("\t");
    std::cout << tabs << "ASTReturnStatementNode Expr" << std::endl;
}

void ASTReturnStatementNode::Accept(Visitor *v) {
    v->visit(this);
}
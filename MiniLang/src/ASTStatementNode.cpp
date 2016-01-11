//
// Created by sandro on 1/11/16.
//

#include "ASTStatementNode.h"

ASTStatementNode::ASTStatementNode() {
    // TODO Auto-generated constructor stub
}

ASTStatementNode::~ASTStatementNode() {
    // TODO Auto-generated destructor stub
}

void ASTStatementNode::PrintInfo(int p_level) {
    std::string tabs = "";
    for (int t = 0; t<p_level; t++) tabs.append("\t");
    std::cout << tabs << "ASTStatementNode [StatementBase]" << std::endl;
}
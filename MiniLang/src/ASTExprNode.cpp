/*
 * ASTExprNode.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#include "ASTExprNode.h"

ASTExprNode::ASTExprNode() {
	// TODO Auto-generated constructor stub
}

ASTExprNode::~ASTExprNode() {
	// TODO Auto-generated destructor stub
}

void ASTExprNode::PrintInfo(int p_level) {
	std::string tabs = "";
	for (int t = 0; t<p_level; t++) tabs.append("\t");
	std::cout << tabs << "ASTExprNode [ExprBase]" << std::endl;
}

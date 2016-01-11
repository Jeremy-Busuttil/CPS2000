/*
 * ASTBinaryExprNode.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#include "ASTBinaryExprNode.h"

ASTBinaryExprNode::ASTBinaryExprNode(char p_Op, std::unique_ptr<ASTExprNode> p_LHS, std::unique_ptr<ASTExprNode> p_RHS) :
	Op(p_Op),
	LHS(std::move(p_LHS)),
	RHS(std::move(p_RHS))
{
	// TODO Auto-generated constructor stub
}

ASTBinaryExprNode::~ASTBinaryExprNode() {
	// TODO Auto-generated destructor stub
}

void ASTBinaryExprNode::PrintInfo(int p_level) {
	std::string tabs = "";
	for (int t = 0; t<p_level; t++) tabs.append("\t");
	std::cout << tabs << "ASTBinaryExprNode [" << Op << "]" << std::endl;
	LHS->PrintInfo(p_level+1);
	RHS->PrintInfo(p_level+1);
}



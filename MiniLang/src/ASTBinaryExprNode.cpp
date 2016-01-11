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

void ASTBinaryExprNode::PrintInfo() {
	std::cout << "ASTBinaryExprNode LHS=";
	LHS->PrintInfo();
	std::cout << "RHS=" << std::endl;
	RHS->PrintInfo();
}



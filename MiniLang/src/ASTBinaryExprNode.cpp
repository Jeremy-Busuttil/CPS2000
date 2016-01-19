/*
 * ASTBinaryExprNode.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#include "ASTBinaryExprNode.h"
#include "Visitor.h"

ASTBinaryExprNode::ASTBinaryExprNode(char p_Op, ASTExprNode * p_LHS, ASTExprNode * p_RHS) :
	Op(p_Op),
	LHS(p_LHS),
	RHS(p_RHS)
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

//llvm::Value * ASTBinaryExprNode::CodeGen() {
//	return nullptr;
//}

void ASTBinaryExprNode::Accept(Visitor * v) {
	v->visit(this);
}

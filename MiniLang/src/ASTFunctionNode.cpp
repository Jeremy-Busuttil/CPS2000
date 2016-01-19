/*
 * ASTFunctionNode.cpp
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#include "ASTFunctionNode.h"

ASTFunctionNode::ASTFunctionNode(ASTFuncPrototypeNode * p_Prototype, ASTStatementNode * p_Body)
: Proto(p_Prototype), Body(p_Body)
{
	// TODO Auto-generated constructor stub
}

ASTFunctionNode::~ASTFunctionNode() {
	// TODO Auto-generated destructor stub
}

void ASTFunctionNode::PrintInfo(int p_level) {
	std::cout << "ASTFunctionNode" << std::endl;
}

void ASTFunctionNode::Accept(Visitor * v) {
	v->visit(this);
}
/*
 * ASTNumberExprNode.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#include "ASTNumberExprNode.h"

ASTNumberExprNode::ASTNumberExprNode(float p_Value) : Value(p_Value) {
	// TODO Auto-generated constructor stub
}

ASTNumberExprNode::~ASTNumberExprNode() {
	// TODO Auto-generated destructor stub
}

void ASTNumberExprNode::PrintInfo() {
	std::cout << "ASTNumberExprNode [" << std::to_string(Value) << "]" << std::endl;
}

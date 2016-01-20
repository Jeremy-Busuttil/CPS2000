/*
 * ASTNumberExprNode.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#include "ASTNumberExprNode.h"

ASTNumberExprNode::ASTNumberExprNode(float p_Value) : numberValue(p_Value) {
	// TODO Auto-generated constructor stub
}

ASTNumberExprNode::~ASTNumberExprNode() {
	// TODO Auto-generated destructor stub
}

void ASTNumberExprNode::PrintInfo(int p_level) {
	std::string tabs = "";
	for (int t = 0; t<p_level; t++) tabs.append("\t");
	std::cout << tabs << "ASTNumberExprNode [" << std::to_string(numberValue) << "]" << std::endl;
}

void ASTNumberExprNode::Accept(Visitor *v) {
	v->visit(this);
}

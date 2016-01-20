/*
 * ASTCallExprNode.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#include "ASTCallExprNode.h"

ASTCallExprNode::ASTCallExprNode(std::string p_FunctionName, std::vector<ASTExprNode*> p_Args)
	:	FunctionName(p_FunctionName),
		Args(p_Args)
{
	// TODO Auto-generated constructor stub

}

ASTCallExprNode::~ASTCallExprNode() {
	// TODO Auto-generated destructor stub
}

void ASTCallExprNode::PrintInfo(int p_level) {
	std::cout << "ASTCallExprNode " << FunctionName << std::endl;
}

void ASTCallExprNode::Accept(Visitor *v) {
	v->visit(this);
}

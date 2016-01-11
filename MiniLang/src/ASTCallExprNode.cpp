/*
 * ASTCallExprNode.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#include "ASTCallExprNode.h"

ASTCallExprNode::ASTCallExprNode(std::string p_FunctionName, std::vector<std::unique_ptr<ASTExprNode>> p_Args)
	:	FunctionName(p_FunctionName),
		Args(std::move(p_Args))
{
	// TODO Auto-generated constructor stub

}

ASTCallExprNode::~ASTCallExprNode() {
	// TODO Auto-generated destructor stub
}

void ASTCallExprNode::PrintInfo() {
	std::cout << "ASTCallExprNode " << FunctionName << std::endl;
}


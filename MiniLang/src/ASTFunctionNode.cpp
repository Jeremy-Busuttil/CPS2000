/*
 * ASTFunctionNode.cpp
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#include "ASTFunctionNode.h"

ASTFunctionNode::ASTFunctionNode(std::unique_ptr<ASTFuncPrototypeNode> p_Prototype, std::unique_ptr<ASTStatementNode> p_Body)
//: Prototype(std::move(p_Prototype)), Body(p_Body)
{
	// TODO Auto-generated constructor stub

}

ASTFunctionNode::~ASTFunctionNode() {
	// TODO Auto-generated destructor stub
}

void ASTFunctionNode::PrintInfo(int p_level) {
	std::cout << "ASTFunctionNode" << std::endl;
}


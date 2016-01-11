/*
 * ASTFuncPrototypeNode.cpp
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#include "ASTFuncPrototypeNode.h"

ASTFuncPrototypeNode::ASTFuncPrototypeNode(const std::string &p_Name, std::vector<std::string> p_Args)
	:   Name (p_Name),
		Args (p_Args)
{
	// TODO Auto-generated constructor stub

}

ASTFuncPrototypeNode::~ASTFuncPrototypeNode() {
	// TODO Auto-generated destructor stub
}

void ASTFuncPrototypeNode::PrintInfo() {
	std::cout << "ASTFuncPrototypeNode" << std::endl;
}

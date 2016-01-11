/*
 * ASTNode.cpp
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#include "ASTNode.h"

ASTNode::ASTNode() {
	// TODO Auto-generated constructor stub
}

ASTNode::~ASTNode() {
	// TODO Auto-generated destructor stub
}

void ASTNode::PrintInfo(int p_level) {
	std::string tabs = "";
	for (int t = 0; t<p_level; t++) tabs.append("\t");
	std::cout << tabs << "ASTNode [BASE]" << std::endl;
}

void ASTNode::Initialise() {
}

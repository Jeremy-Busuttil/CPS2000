/*
 * ASTVariableExprNode.h
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#ifndef ASTVARIABLEEXPRNODE_H_
#define ASTVARIABLEEXPRNODE_H_

#include "ASTExprNode.h"
#include <string>

class ASTVariableExprNode: public ASTExprNode {
public:
	ASTVariableExprNode(const std::string &Name);
	virtual ~ASTVariableExprNode();


	std::string Name;
	virtual void PrintInfo() override;
};

#endif /* ASTVARIABLEEXPRNODE_H_ */

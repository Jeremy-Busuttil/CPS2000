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

	virtual void Accept(class Visitor * v);
	//virtual llvm::Value * CodeGen();
	virtual void PrintInfo(int p_level) override;
};

#endif /* ASTVARIABLEEXPRNODE_H_ */

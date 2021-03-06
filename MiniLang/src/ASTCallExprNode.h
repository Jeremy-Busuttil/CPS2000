/*
 * ASTCallExprNode.h
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#ifndef ASTCALLEXPRNODE_H_
#define ASTCALLEXPRNODE_H_

#include "ASTExprNode.h"

#include <vector>
#include <string>

class ASTCallExprNode: public ASTExprNode {
public:
	ASTCallExprNode(std::string p_FunctionName, std::vector<ASTExprNode*> p_Args);
	virtual ~ASTCallExprNode();

	std::string FunctionName;
	std::vector<ASTExprNode*> Args;

	virtual void Accept(Visitor * v);
	//virtual llvm::Value * CodeGen();
	virtual void PrintInfo(int p_level) override;
};

#endif /* ASTCALLEXPRNODE_H_ */

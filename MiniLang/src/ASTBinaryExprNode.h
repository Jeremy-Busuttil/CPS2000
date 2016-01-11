/*
 * ASTBinaryExprNode.h
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#ifndef ASTBINARYEXPRNODE_H_
#define ASTBINARYEXPRNODE_H_

#include "ASTExprNode.h"
#include <memory>

class ASTBinaryExprNode: public ASTExprNode {
public:
	ASTBinaryExprNode(char p_Op, std::unique_ptr<ASTExprNode> p_LHS, std::unique_ptr<ASTExprNode> p_RHS);
	virtual ~ASTBinaryExprNode();

	char Op;
	std::unique_ptr<ASTExprNode> LHS, RHS;

	virtual void PrintInfo() override;
};

#endif /* ASTBINARYEXPRNODE_H_ */

/*
 * ASTBinaryExprNode.h
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#ifndef ASTBINARYEXPRNODE_H_
#define ASTBINARYEXPRNODE_H_

#include "ASTExprNode.h"

class ASTBinaryExprNode: public ASTExprNode {
public:
	ASTBinaryExprNode(char p_Op, ASTExprNode * p_LHS, ASTExprNode * p_RHS);
	virtual ~ASTBinaryExprNode();

	char Op;
	ASTExprNode * LHS;
	ASTExprNode * RHS;

    virtual void Accept(Visitor * v) override;
	virtual void PrintInfo(int p_level) override;

    //virtual llvm::Value * CodeGen();
};

#endif /* ASTBINARYEXPRNODE_H_ */

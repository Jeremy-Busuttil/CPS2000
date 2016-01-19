/*
 * ASTNumberExprNode.h
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#ifndef ASTNUMBEREXPRNODE_H_
#define ASTNUMBEREXPRNODE_H_

#include "ASTExprNode.h"

class ASTNumberExprNode: public ASTExprNode {
public:
	ASTNumberExprNode(float p_Value);
	virtual ~ASTNumberExprNode();

	float numberValue;

    virtual void PrintInfo(int p_level) override;
	virtual void Accept(Visitor * v) override;
	//virtual llvm::Value * CodeGen();
};

#endif /* ASTNUMBEREXPRNODE_H_ */

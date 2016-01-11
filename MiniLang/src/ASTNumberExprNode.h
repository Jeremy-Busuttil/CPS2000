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

	float Value;
	virtual void PrintInfo() override;
};

#endif /* ASTNUMBEREXPRNODE_H_ */

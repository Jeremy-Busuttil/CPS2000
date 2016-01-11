/*
 * ASTExprNode.h
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#ifndef ASTEXPRNODE_H_
#define ASTEXPRNODE_H_

#include "ASTNode.h"

class ASTExprNode : public ASTNode {
public:
	ASTExprNode();
	virtual ~ASTExprNode();

	virtual void PrintInfo() override;
};

#endif /* ASTEXPRNODE_H_ */

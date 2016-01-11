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

	virtual void PrintInfo(int p_level) override;
};

#endif /* ASTEXPRNODE_H_ */

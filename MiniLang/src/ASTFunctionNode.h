/*
 * ASTFunctionNode.h
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#ifndef ASTFUNCTIONNODE_H_
#define ASTFUNCTIONNODE_H_

#include "ASTFuncPrototypeNode.h"
#include "ASTStatementNode.h"

class ASTFunctionNode : public ASTNode {
public:
	ASTFunctionNode(ASTFuncPrototypeNode * p_Prototype, ASTStatementNode * p_Body);

	virtual ~ASTFunctionNode();

	ASTFuncPrototypeNode * Proto;
	ASTStatementNode * Body;

	virtual void Accept(Visitor * v) override;
	virtual void PrintInfo(int p_level) override;
};

#endif /* ASTFUNCTIONNODE_H_ */

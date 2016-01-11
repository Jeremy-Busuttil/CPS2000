/*
 * ASTFunctionNode.h
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#ifndef ASTFUNCTIONNODE_H_
#define ASTFUNCTIONNODE_H_

#include <memory>
#include "ASTFuncPrototypeNode.h"
#include "ASTStatementNode.h"

class ASTFunctionNode : ASTNode {
public:
	ASTFunctionNode(std::unique_ptr<ASTFuncPrototypeNode> p_Prototype, std::unique_ptr<ASTStatementNode> p_Body);
	virtual ~ASTFunctionNode();

	std::unique_ptr<ASTFuncPrototypeNode> Prototype;
	std::unique_ptr<ASTStatementNode> Body;

	virtual void PrintInfo(int p_level) override;
};

#endif /* ASTFUNCTIONNODE_H_ */

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
#include <memory>

class ASTCallExprNode: public ASTExprNode {
public:
	ASTCallExprNode(std::string p_FunctionName, std::vector<std::unique_ptr<ASTExprNode>> p_Args);
	virtual ~ASTCallExprNode();

	std::string FunctionName;
	std::vector<std::unique_ptr<ASTExprNode>> Args;
	virtual void PrintInfo() override;
};

#endif /* ASTCALLEXPRNODE_H_ */

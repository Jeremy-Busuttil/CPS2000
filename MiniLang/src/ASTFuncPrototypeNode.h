/*
 * ASTFuncPrototypeNode.h
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#ifndef ASTFUNCPROTOTYPENODE_H_
#define ASTFUNCPROTOTYPENODE_H_

#include <string>
#include <vector>

#include "ASTNode.h"

class ASTFuncPrototypeNode : public ASTNode {
public:
	ASTFuncPrototypeNode(const std::string &p_Name, std::vector<std::string> p_Args);

	virtual ~ASTFuncPrototypeNode();

	std::string Name;
	std::vector<std::string> Args;

    virtual void Accept(Visitor * v) override;
	virtual void PrintInfo(int p_level) override;
};

#endif /* ASTFUNCPROTOTYPENODE_H_ */

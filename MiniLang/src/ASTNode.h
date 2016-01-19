/*
 * ASTNode.h
 *
 *  Created on: Jan 5, 2016
 *      Author: sandro
 */

#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <string>
#include <iostream>
#include <fstream>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"

#include "Visitor.h"

class ASTNode {
public:
	ASTNode();
	virtual ~ASTNode();

	void Initialise();

    virtual void Accept(Visitor * v) = 0;
	virtual void PrintInfo(int p_level);
};

#endif /* ASTNODE_H_ */

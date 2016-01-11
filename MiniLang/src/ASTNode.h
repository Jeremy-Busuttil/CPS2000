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

class ASTNode {
public:
	ASTNode();
	virtual ~ASTNode();

	void Initialise();

	virtual void PrintInfo();
};

#endif /* ASTNODE_H_ */

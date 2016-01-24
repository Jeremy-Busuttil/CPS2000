//
// Created by sandro on 1/24/16.
//

#ifndef CPS2000_MINILANG_ASTPROGRAMNODE_H
#define CPS2000_MINILANG_ASTPROGRAMNODE_H

#include "ASTNode.h"

class ASTProgramNode : public ASTNode {

public:
    ASTProgramNode();
    virtual ~ASTProgramNode();

    std::vector<ASTFunctionNode * > * functions;
    std::vector<ASTStatementNode * > * main_impl;

    virtual void Accept(Visitor * v) override;
    virtual void PrintInfo(int p_level);

};


#endif //CPS2000_MINILANG_ASTPROGRAMNODE_H

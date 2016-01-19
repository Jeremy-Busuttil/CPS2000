//
// Created by sandro on 1/19/16.
//

#ifndef CPS2000_MINILANG_VISITOR_H
#define CPS2000_MINILANG_VISITOR_H

#include "ASTNode.h"
#include "ASTExprNode.h"
#include "ASTVariableExprNode.h"
#include "ASTBinaryExprNode.h"
#include "ASTCallExprNode.h"
#include "ASTNumberExprNode.h"

class Visitor {
public:
    virtual void visit(ASTExprNode*) = 0;
    virtual void visit(ASTNumberExprNode*) = 0;
    virtual void visit(ASTVariableExprNode*) = 0;
    virtual void visit(ASTBinaryExprNode*) = 0;
    virtual void visit(ASTCallExprNode*) = 0;
};


#endif //CPS2000_MINILANG_VISITOR_H

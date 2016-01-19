//
// Created by sandro on 1/19/16.
//

#ifndef CPS2000_MINILANG_PRINTINFOVISITOR_H
#define CPS2000_MINILANG_PRINTINFOVISITOR_H

#include "Visitor.h"

class PrintInfoVisitor : public Visitor {

    int Indent = 0;

public:

    PrintInfoVisitor();
    virtual void visit(ASTExprNode*);
    virtual void visit(ASTNumberExprNode*);
    virtual void visit(ASTVariableExprNode*);
    virtual void visit(ASTBinaryExprNode*);
    virtual void visit(ASTCallExprNode*);

};


#endif //CPS2000_MINILANG_PRINTINFOVISITOR_H

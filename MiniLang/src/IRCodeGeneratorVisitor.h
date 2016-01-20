//
// Created by sandro on 1/20/16.
//

#ifndef CPS2000_MINILANG_IRCODEGENERATORVISITOR_H
#define CPS2000_MINILANG_IRCODEGENERATORVISITOR_H

#include "Visitor.h"

#include <string>
#include <iostream>
#include <fstream>



class IRCodeGeneratorVisitor : public Visitor {

  public:



    IRCodeGeneratorVisitor();
    virtual void visit(ASTExprNode* p_node);
    virtual void visit(ASTNumberExprNode* p_node);
    virtual void visit(ASTVariableExprNode* p_node);
    virtual void visit(ASTBinaryExprNode* p_node);
    virtual void visit(ASTCallExprNode* p_node);
    virtual void visit(ASTIfStatementNode* p_node);
    virtual void visit(ASTStatementNode* p_node);
    virtual void visit(ASTFunctionNode* p_node);
    virtual void visit(ASTFuncPrototypeNode* p_node);
    virtual void visit(ASTAssignmentStatementNode* p_node);


};


#endif //CPS2000_MINILANG_IRCODEGENERATORVISITOR_H

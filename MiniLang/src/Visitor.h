//
// Created by sandro on 1/19/16.
//

#ifndef CPS2000_MINILANG_VISITOR_H
#define CPS2000_MINILANG_VISITOR_H

class ASTNode;
class ASTExprNode;
class ASTVariableExprNode;
class ASTBinaryExprNode;
class ASTCallExprNode;
class ASTNumberExprNode;
class ASTIfStatementNode;
class ASTStatementNode;
class ASTFunctionNode;
class ASTFuncPrototypeNode;
class ASTAssignmentStatementNode;
class ASTDeclarationStatementNode;
class ASTReturnStatementNode;
class ASTProgramNode;

class Visitor {
public:
    virtual void visit(ASTExprNode*) = 0;
    virtual void visit(ASTNumberExprNode*) = 0;
    virtual void visit(ASTVariableExprNode*) = 0;
    virtual void visit(ASTBinaryExprNode*) = 0;
    virtual void visit(ASTCallExprNode*) = 0;
    virtual void visit(ASTIfStatementNode*) = 0;
    virtual void visit(ASTStatementNode*) = 0;
    virtual void visit(ASTFunctionNode*) = 0;
    virtual void visit(ASTFuncPrototypeNode*) = 0;
    virtual void visit(ASTAssignmentStatementNode*) = 0;
    virtual void visit(ASTReturnStatementNode*) = 0;
    virtual void visit(ASTProgramNode*) = 0;
};

#endif //CPS2000_MINILANG_VISITOR_H

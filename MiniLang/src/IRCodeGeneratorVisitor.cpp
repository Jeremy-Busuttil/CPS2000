//
// Created by sandro on 1/20/16.
//

#include "IRCodeGeneratorVisitor.h"
#include "ASTNumberExprNode.h"
#include "ASTBinaryExprNode.h"
#include "ASTVariableExprNode.h"


IRCodeGeneratorVisitor::IRCodeGeneratorVisitor() {
    std::cout << "[IRCodeGeneratorVisitor] " << std::endl;
}

void IRCodeGeneratorVisitor::visit(ASTExprNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTNumberExprNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTVariableExprNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTBinaryExprNode * p_node) {
    p_node->LHS->Accept(this);
    p_node->RHS->Accept(this);
}

void IRCodeGeneratorVisitor::visit(ASTCallExprNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTIfStatementNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTStatementNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTFunctionNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTFuncPrototypeNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTAssignmentStatementNode * p_node) {

}
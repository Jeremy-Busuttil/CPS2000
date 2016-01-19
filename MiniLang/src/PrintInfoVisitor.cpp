//
// Created by sandro on 1/19/16.
//

#include "PrintInfoVisitor.h"
#include "ASTNumberExprNode.h"
#include "ASTBinaryExprNode.h"
#include "ASTVariableExprNode.h"


PrintInfoVisitor::PrintInfoVisitor() : Indent(0) {
    std::cout << "[PrintInfoVisitor] " << std::endl;
}

void PrintInfoVisitor::visit(ASTExprNode * p_node) {

}

void PrintInfoVisitor::visit(ASTNumberExprNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTNumberExprNode [" << std::to_string(p_node->numberValue) << "]" << std::endl;
}

void PrintInfoVisitor::visit(ASTVariableExprNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTVariableExprNode [" << p_node->Name <<  "]" <<std::endl;
}

void PrintInfoVisitor::visit(ASTBinaryExprNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTBinaryExprNode [" << p_node->Op << "]" << std::endl;
    Indent++;
    p_node->LHS->Accept(this);
    p_node->RHS->Accept(this);
    Indent--;
}

void PrintInfoVisitor::visit(ASTCallExprNode * p_node) {

}

void PrintInfoVisitor::visit(ASTIfStatementNode * p_node) {

}

void PrintInfoVisitor::visit(ASTStatementNode * p_node) {

}

void PrintInfoVisitor::visit(ASTFunctionNode * p_node) {

}

void PrintInfoVisitor::visit(ASTFuncPrototypeNode * p_node) {

}

void PrintInfoVisitor::visit(ASTAssignmentStatementNode * p_node) {

}
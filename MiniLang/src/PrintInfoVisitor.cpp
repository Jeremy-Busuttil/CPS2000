//
// Created by sandro on 1/19/16.
//

#include "PrintInfoVisitor.h"
#include "ASTNumberExprNode.h"
#include "ASTBinaryExprNode.h"
#include "ASTVariableExprNode.h"
#include "ASTFunctionNode.h"
#include "ASTReturnStatementNode.h"
#include "ASTDeclarationStatementNode.h"
#include "ASTAssignmentStatementNode.h"
#include "ASTProgramNode.h"

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
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTFunctionNode " << std::endl;
    Indent++;
    p_node->Proto->Accept(this);
    tabs.clear();
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTFunctionBody " << std::endl;
    Indent++;
    for (int i=0; i<p_node->Body->size(); i++) p_node->Body->at(i)->Accept(this);
    Indent--;
    Indent--;
}

void PrintInfoVisitor::visit(ASTFuncPrototypeNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTFunctionPrototype " << p_node->Name << " ";
    for (int i = 0; i<p_node->Args.size(); i++) std::cout << p_node->Args[i] << " ";
    std::cout << std::endl;
}

void PrintInfoVisitor::visit(ASTDeclarationStatementNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTDeclarationNode " << p_node->varType << std::endl;
    Indent++;
    p_node->RHS->Accept(this);
    Indent--;

}

void PrintInfoVisitor::visit(ASTAssignmentStatementNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTAssignmentNode " << std::endl;
    Indent++;
    tabs.clear();
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << p_node->LHS << std::endl;
    p_node->RHS->Accept(this);
    Indent--;
}

void PrintInfoVisitor::visit(ASTReturnStatementNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTReturnStatement " << std::endl;
    p_node->LHS->Accept(this);
}

void PrintInfoVisitor::visit(ASTProgramNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t < Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTProgramNode " << std::endl;
    Indent++;
    for (int i = 0; i < p_node->functions->size(); i++)
        p_node->functions->at(i)->Accept(this);

    for (int i = 0; i < p_node->main_impl->size(); i++)
        p_node->main_impl->at(i)->Accept(this);
    Indent--;
}
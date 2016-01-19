//
// Created by sandro on 1/19/16.
//

#include "PrintInfoVisitor.h"


PrintInfoVisitor::PrintInfoVisitor() : Indent(0) {
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
    std::cout << tabs << "ASTVariableExprNode [" << p_node->Name << "]" <<std::endl;
}

void PrintInfoVisitor::visit(ASTBinaryExprNode * p_node) {
    std::string tabs = "";
    for (int t = 0; t<Indent; t++) tabs.append("\t");
    std::cout << tabs << "ASTBinaryExprNode [" << p_node->Op << "]" << std::endl;

    //visit(p_node->LHS);

    //LHS->PrintInfo(p_level+1);
    //RHS->PrintInfo(p_level+1);
}

void PrintInfoVisitor::visit(ASTCallExprNode*) {

}

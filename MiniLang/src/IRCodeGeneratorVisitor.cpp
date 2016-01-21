//
// Created by sandro on 1/20/16.
//

#include "IRCodeGeneratorVisitor.h"
#include "ASTNumberExprNode.h"
#include "ASTBinaryExprNode.h"
#include "ASTVariableExprNode.h"


IRCodeGeneratorVisitor::IRCodeGeneratorVisitor(llvm::Module * p_module, llvm::IRBuilder<> p_builder, std::map<std::string, llvm::Value *> p_namedValues) :
    module(p_module), builder(p_builder), namedValues(p_namedValues)
{
    std::cout << "[IRCodeGeneratorVisitor] Constructor" << std::endl;
}

void IRCodeGeneratorVisitor::visit(ASTExprNode * p_node) {

}

void IRCodeGeneratorVisitor::visit(ASTNumberExprNode * p_node) {
    std::cout << "[IRCodeGeneratorVisitor] Visiting ASTNumberExprNode" << std::endl;
    crtValue = llvm::ConstantFP::get(llvm::getGlobalContext(), llvm::APFloat(p_node->numberValue));
}

void IRCodeGeneratorVisitor::visit(ASTVariableExprNode * p_node) {
    std::cout << "[IRCodeGeneratorVisitor] Visiting ASTVariableExprNode" << std::endl;
    crtValue = namedValues[p_node->Name];
    if (!crtValue)
    {
        std::cout << "[IRCodeGeneratorVisitor] Unknown variable name" << std::endl;
    }
}

void IRCodeGeneratorVisitor::visit(ASTBinaryExprNode * p_node) {
    std::cout << "[IRCodeGeneratorVisitor] Visiting ASTBinaryExprNode" << std::endl;
    p_node->LHS->Accept(this);
    llvm::Value * L = crtValue;

    p_node->RHS->Accept(this);
    llvm::Value * R = crtValue;

    switch (p_node->Op)
    {
        case '+':
            crtValue = builder.CreateFAdd(L, R, "addtmp");
            break;
        case '-':
            crtValue = builder.CreateFSub(L, R, "subtmp");
            break;
        case '*':
            crtValue = builder.CreateFMul(L, R, "multmp");
            break;
        case  '\\':
            crtValue = builder.CreateFDiv(L, R, "divtmp");
            break;
        default:
        std::cout << "[IRCodeGeneratorVisitor] Invalid binary operator" << std::endl;
    }
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
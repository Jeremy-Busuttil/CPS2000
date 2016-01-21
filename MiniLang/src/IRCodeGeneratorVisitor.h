//
// Created by sandro on 1/20/16.
//

#ifndef CPS2000_MINILANG_IRCODEGENERATORVISITOR_H
#define CPS2000_MINILANG_IRCODEGENERATORVISITOR_H

#include "Visitor.h"

#include <string>
#include <iostream>
#include <fstream>

#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

class IRCodeGeneratorVisitor : public Visitor {

  public:

    llvm::Module * module = nullptr;
    llvm::IRBuilder<> builder;
    std::map<std::string, llvm::Value *> namedValues;

    //Initialise with an undef value. Will be updated by all visit functions
    llvm::Value * crtValue = llvm::ConstantFP::get(llvm::getGlobalContext(), llvm::APFloat(0.f));

    IRCodeGeneratorVisitor(llvm::Module * p_module, llvm::IRBuilder<> p_builder, std::map<std::string, llvm::Value *> p_namedValues);
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

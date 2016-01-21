//============================================================================
// Name        : CPS2000-LLVM_Project.cpp
// Author      : Sandro Spina
// Version     :
// Copyright   : haha
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "PrintInfoVisitor.h"
#include "IRCodeGeneratorVisitor.h"

#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

using namespace std;

int main() {
	//Lexer * lex = new Lexer("./Resource/test.prog");
	Lexer * lex = new Lexer("./resources/simple_expr.prog");
	cout << lex->ToString() << endl;
	Parser * parser = new Parser(*lex);
	auto rootNode = parser->Parse();
    std::cout << "Print AST using PrintInfo ASTNode functions" << std::endl;
	rootNode->PrintInfo(0);

    std::cout << "\nPrint AST using PrintInfoVisitor" << std::endl;
	PrintInfoVisitor * pv = new PrintInfoVisitor();
    rootNode->Accept(pv);

    llvm::Module * TheModule;
    llvm::IRBuilder<> Builder(llvm::getGlobalContext());
    std::map<std::string, llvm::Value *> NamedValues;

    std::cout << "\nIR Code Generation of AST using IRCodeGeneratorVisitor" << std::endl;
    IRCodeGeneratorVisitor * cg = new IRCodeGeneratorVisitor();
    rootNode->Accept(cg);

	//Lexer::Token nxtToken = lex->GetToken();
	//while (nxtToken.token_type != Lexer::TOK_EOF)
	//{
	//	cout << nxtToken.ToString() << " ";
	//	nxtToken = lex->GetToken();
	//}
	//cout << nxtToken.ToString() << endl;

	return 0;
}

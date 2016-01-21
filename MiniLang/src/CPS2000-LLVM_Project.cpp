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
	//Lexer * lex = new Lexer("./resources/simple_expr.prog");
    Lexer * lex = new Lexer("./resources/simple_func_def.prog");
	cout << lex->ToString() << endl;
	Parser * parser = new Parser(*lex);
	auto rootNode = parser->Parse();
    std::cout << "Print AST using PrintInfo ASTNode functions" << std::endl;
	rootNode->PrintInfo(0);

    std::cout << "\nPrint AST using PrintInfoVisitor" << std::endl;
	PrintInfoVisitor * pv = new PrintInfoVisitor();
    rootNode->Accept(pv);

    std::cout << "\nIR Code Generation of AST using IRCodeGeneratorVisitor" << std::endl;
    llvm::Module * module = new llvm::Module("MiniLangCompiler", llvm::getGlobalContext());
    llvm::IRBuilder<> builder(llvm::getGlobalContext());
    std::map<std::string, llvm::Value *> namedValues;
    IRCodeGeneratorVisitor * cg = new IRCodeGeneratorVisitor(module, builder, namedValues);
    rootNode->Accept(cg);
    std::cout << "Root ASTNode Value->dump()" << std::endl;
    cg->crtValue->dump();

    std::cout << "\nIRBuilder->dump()" << std::endl;
    //module->dump();



    /*
	Lexer::Token nxtToken = lex->GetToken();
	while (nxtToken.token_type != Lexer::TOK_EOF)
	{
		cout << nxtToken.ToString() << " ";
		nxtToken = lex->GetToken();
	}
	cout << nxtToken.ToString() << endl;
     */

	return 0;
}

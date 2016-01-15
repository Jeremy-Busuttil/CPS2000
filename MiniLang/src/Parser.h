/*
 * Parser.h
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <memory>
#include <vector>

#include "Lexer.h"
//AST Expression Nodes
#include "ASTExprNode.h"
#include "ASTNumberExprNode.h"
#include "ASTVariableExprNode.h"
#include "ASTCallExprNode.h"
#include "ASTBinaryExprNode.h"

//AST Statement Nodes
#include "ASTStatementNode.h"
#include "ASTIfStatementNode.h"
#include "ASTAssignmentStatementNode.h"

//AST Function Nodes
#include "ASTFunctionNode.h"
#include "ASTFuncPrototypeNode.h"

//LLVM includes
#include "llvm/IR/Module.h"

// Cloning make_unique here until it's standard in C++14.
template <class T, class... Args>
static
    typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
    make_unique(Args &&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class Parser {
public:
	Parser(Lexer p_Lexer);
	virtual ~Parser();

private:
	Lexer Lex;
	Lexer::Token CurrentToken;

	std::unique_ptr<ASTExprNode> Error(const char *Str);
	std::unique_ptr<ASTExprNode> ParseNumberExpr();
	std::unique_ptr<ASTExprNode> ParseParenthesisExpr();
	std::unique_ptr<ASTExprNode> ParseIdentifierExpr();
	std::unique_ptr<ASTExprNode> ParseUnaryExpr();
	std::unique_ptr<ASTExprNode> ParseBinaryExpr(int p_Precedence, std::unique_ptr<ASTExprNode> p_LHS);
	std::unique_ptr<ASTExprNode> ParseExpression();

	std::unique_ptr<ASTFuncPrototypeNode> ParseFunctionPrototype();
	std::unique_ptr<ASTStatementNode> ParseFunctionBody();
	std::unique_ptr<ASTFunctionNode> ParseFunctionDefinition();

	std::unique_ptr<ASTStatementNode> ParseIfStatement();
	std::unique_ptr<ASTStatementNode> ParseAssignmentStatement();

	std::unique_ptr<ASTExprNode> Parse();
};

#endif /* PARSER_H_ */

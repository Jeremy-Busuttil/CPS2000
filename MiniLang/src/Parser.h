/*
 * Parser.h
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#ifndef PARSER_H_
#define PARSER_H_

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

class Parser {
public:
	Parser(Lexer p_Lexer);
	virtual ~Parser();

	ASTNode * Parse();

private:
	Lexer Lex;
	Lexer::Token CurrentToken;

	ASTExprNode * Error(const char *Str);
	ASTExprNode * ParseNumberExpr();
	ASTExprNode * ParseParenthesisExpr();
	ASTExprNode * ParseIdentifierExpr();
	ASTExprNode * ParseUnaryExpr();
	ASTExprNode * ParseBinaryExpr(int p_Precedence, ASTExprNode * p_LHS);
	ASTExprNode * ParseExpression();

	ASTFuncPrototypeNode * ParseFunctionPrototype();
	ASTStatementNode * ParseFunctionBody();
	ASTFunctionNode * ParseFunctionDefinition();

	ASTStatementNode * ParseIfStatement();
	ASTStatementNode * ParseAssignmentStatement();
};

#endif /* PARSER_H_ */

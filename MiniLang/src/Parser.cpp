/*
 * Parser.cpp
 *
 *  Created on: Jan 6, 2016
 *      Author: sandro
 */

#include "Parser.h"

Parser::Parser(Lexer p_lexer) : Lex(p_lexer) {
	// TODO Auto-generated constructor stub
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

ASTExprNode * Parser::Error(const char *p_Str)
{
	std::cout << "Error: " << p_Str << std::endl;
	return nullptr;
}

ASTExprNode * Parser::ParseNumberExpr()
{
	auto node = new ASTNumberExprNode(CurrentToken.number_value);
	CurrentToken = Lex.GetToken();
	return node;
}

ASTExprNode * Parser::ParseParenthesisExpr()
{
	CurrentToken = Lex.GetToken();
	auto node = ParseExpression();
	if (!node) return nullptr;
	if (CurrentToken.token_type != Lexer::TOK_PUNC)
	{
		std::string err_msg = "Encountered " + CurrentToken.ToString() + ", expecting TOK_PUNC [)]";
		return Error(err_msg.c_str());
	}
	else
	{
		CurrentToken = Lex.GetToken();
		return node;
	}
}

ASTExprNode * Parser::ParseIdentifierExpr()
{
	std::string Name = CurrentToken.id_name;
	CurrentToken = Lex.GetToken();
	if (CurrentToken.token_type == Lexer::TOK_PUNC || CurrentToken.token_type == Lexer::TOK_ARITHMETICOP || CurrentToken.token_type == Lexer::TOK_STMT_DELIMITER)
	{
		return new ASTVariableExprNode(Name);
	}
	else
	{
		if (CurrentToken.id_name.compare("(") == 0)
		{
			CurrentToken = Lex.GetToken();
			//This is a function call. Start argument parsing.

			std::vector<ASTExprNode *> args;
			while (true && CurrentToken.token_type!=Lexer::TOK_EOF)
			{
				if (auto arg = ParseExpression())
					args.push_back(std::move(arg));
				else
				{
					std::string err_msg = "Couldn't parse argument list for function " + Name;
					return Error(err_msg.c_str());
				}

				if (CurrentToken.token_type == Lexer::TOK_PUNC)
				{
					if (CurrentToken.id_name.compare(",") == 0)
					{
						//Parse the next argument - do not break the loop
						CurrentToken = Lex.GetToken();
						continue;
					}

					if (CurrentToken.id_name.compare(")") == 0)
					{
						//We're done. Break the loop
						break;
					}

					std::string err_msg = "Encountered " + CurrentToken.ToString() + ", expecting TOK_PUNC [)] or [,]";
					return Error(err_msg.c_str());
				}
			}

			CurrentToken = Lex.GetToken();
			return new ASTCallExprNode(Name, args);
		}

		if (CurrentToken.id_name.compare("[") == 0)
		{
			//Identifier is an array
		}
	}

	return nullptr;
}

ASTExprNode * Parser::ParseUnaryExpr()
{
	switch (CurrentToken.token_type)
	{
		case Lexer::TOK_ID:
			return ParseIdentifierExpr();
		case Lexer::TOK_NUMBER:
			return ParseNumberExpr();
		case Lexer::TOK_PUNC:
			if (CurrentToken.id_name.compare("(") == 0)
				return ParseParenthesisExpr();
			break;
		default: return Error("Oops, got mixed UP!!");
	}
	return nullptr;
}

ASTExprNode * Parser::ParseBinaryExpr(int p_Precedence, ASTExprNode * p_LHS)
{
	while (true)
	{
		if (CurrentToken.token_type == Lexer::TOK_ARITHMETICOP)
		{
			float op_prec = CurrentToken.number_value;
			std::string op_sym = CurrentToken.id_name;

			CurrentToken = Lex.GetToken();

			auto RHS = ParseUnaryExpr();
			if (!RHS)
				return nullptr;

			float nxt_op_prec = CurrentToken.number_value;

			if (op_prec < nxt_op_prec)
			{
				RHS = ParseBinaryExpr(op_prec+1, RHS);
				if (!RHS)
					return nullptr;
			}

			p_LHS = new ASTBinaryExprNode(op_sym[0], p_LHS, RHS);
		}
		else
		{
			//next token is not an arithmetic op, just return this node.
			return p_LHS;
		}

		float op_prec = CurrentToken.number_value;
		std::string op_sym = CurrentToken.id_name;
	}
	return nullptr;
}

ASTExprNode * Parser::ParseExpression()
{
	auto LHS = ParseUnaryExpr();
	if (!LHS)
		return nullptr;

	return ParseBinaryExpr(0, std::move(LHS));
}

ASTStatementNode * Parser::ParseReturnStatement()
{
    CurrentToken = Lex.GetToken();
    auto expr_node = ParseExpression();
    if (!expr_node)
        return nullptr;

    auto node = new ASTReturnStatementNode();
    node->LHS = expr_node;
    return node;
}

ASTStatementNode * Parser::ParseIfStatement()
{
	auto node = new ASTIfStatementNode();
	CurrentToken = Lex.GetToken();
	return node;
}

ASTStatementNode * Parser::ParseDeclarationStatement()
{
    //Declare the new variable and parse as if this is a assignment.
    //NOTE: All variable declarations have to be initialised.

    std::string type = CurrentToken.id_name;
    CurrentToken = Lex.GetToken();
    auto node = ParseAssignmentStatement();
    if (!node)
        return nullptr;

    return new ASTDeclarationStatementNode(type, (ASTAssignmentStatementNode*)node);
}

ASTStatementNode * Parser::ParseAssignmentStatement()
{
	std::string var_name = CurrentToken.id_name;
	CurrentToken = Lex.GetToken();
	if (CurrentToken.token_type != Lexer::TOK_ASSIGNOP)
	{
		Error("Expecting '=' while parsing an assignment statement");
		return nullptr;
	}
	CurrentToken = Lex.GetToken();
	auto expr_node = ParseExpression();
	auto ass_node = new ASTAssignmentStatementNode(var_name.c_str(), expr_node);
    return ass_node;
}

ASTStatementNode * Parser::ParseStatement()
{
    ASTStatementNode * node = nullptr;
    switch(CurrentToken.token_type)
    {
        case Lexer::TOK_RETURN:
            node = ParseReturnStatement();
            break;
        case Lexer::TOK_IF:
            node = ParseIfStatement();
            break;
        case Lexer::TOK_ID:
            node = ParseAssignmentStatement();
            break;
        case Lexer::TOK_SRCLANG_TYPE:
            node = ParseDeclarationStatement();
            break;
        default:
            break;
    }
    if (!node)
        return nullptr;
    return node;
}

ASTFuncPrototypeNode * Parser::ParseFunctionPrototype() {

	if (CurrentToken.token_type != Lexer::TOK_ID) {
		Error("Expecting function name");
		return nullptr;
	}

	std::string functionName = CurrentToken.id_name;
	auto functionParameters = std::vector<std::string>();

	CurrentToken = Lex.GetToken();
	if (CurrentToken.token_type == Lexer::TOK_PUNC) {
        if (CurrentToken.id_name.compare("(") == 0) {
            CurrentToken = Lex.GetToken();
            while (CurrentToken.token_type == Lexer::TOK_ID) {
                functionParameters.push_back(CurrentToken.id_name);
                CurrentToken = Lex.GetToken();
                if (CurrentToken.token_type == Lexer::TOK_PUNC) {
                    if (CurrentToken.id_name.compare(",") == 0) {
                        //Consume comma
                        CurrentToken = Lex.GetToken();
                    }
                }
            }
        }

        if (CurrentToken.token_type == Lexer::TOK_PUNC) {
            if (CurrentToken.id_name.compare(")") == 0) {
                //Discard ')', Create and return a function prototype AST node
                CurrentToken = Lex.GetToken();
                return new ASTFuncPrototypeNode(functionName.c_str(), functionParameters);
            }
            else {
                std::string errorMsg = "Expecting ) after function parameters ";
                errorMsg.append(functionName);
                Error(errorMsg.c_str());
                return nullptr;
            }
        }
    }
    else
    {
        std::string errorMsg = "Expecting ) after function parameters ";
        errorMsg.append(functionName);
        Error(errorMsg.c_str());
        return nullptr;
    }

}

std::vector<ASTStatementNode *> * Parser::ParseFunctionBody()
{
    std::vector<ASTStatementNode *> * nodes = new std::vector<ASTStatementNode *>();
    if (CurrentToken.token_type == Lexer::TOK_OPEN_SCOPE) {
        CurrentToken = Lex.GetToken();
        while (true) {
            auto node = ParseStatement();
            if (!node)
                return nullptr;

            if (CurrentToken.token_type == Lexer::TOK_STMT_DELIMITER) {
                nodes->push_back(node);
                CurrentToken = Lex.GetToken();
                if (CurrentToken.token_type == Lexer::TOK_CLOSE_SCOPE) {
                    CurrentToken = Lex.GetToken();
                    break;
                }
            }
        }
    }
    else
    {
        std::string errorMsg = "Expecting { after function prototype in declaration of ";
        //errorMsg.append(functionName);
        Error(errorMsg.c_str());
        return nullptr;
    }

    return nodes;
}

ASTFunctionNode * Parser::ParseFunctionDefinition()
{
	CurrentToken = Lex.GetToken();
	auto prototype_node = ParseFunctionPrototype();
	if (!prototype_node)
		return nullptr;

	auto functionBody_node = ParseFunctionBody();
    if (!functionBody_node)
        return nullptr;

	return new ASTFunctionNode(prototype_node, functionBody_node);
}

ASTNode * Parser::Parse()
{
	std::cout << "[Parser] Start" << std::endl;
    std::vector<ASTFunctionNode *> * functions = new std::vector<ASTFunctionNode *>();
    std::vector<ASTStatementNode *> * main_impl = new std::vector<ASTStatementNode *>();
	CurrentToken = Lex.GetToken();
	while (CurrentToken.token_type != Lexer::TOK_EOF)
	{
		switch(CurrentToken.token_type)
		{
		    case Lexer::TOK_DEF: {
                auto f_root = ParseFunctionDefinition();
                if (!f_root)
                    CurrentToken = Lex.GetToken();
                else
                    functions->push_back(f_root);
                break;
            }
		    default: {
                auto stmt = ParseStatement();
                if (!stmt)
                    CurrentToken = Lex.GetToken();
				else
                {
                    if (CurrentToken.token_type == Lexer::TOK_STMT_DELIMITER) {
                        main_impl->push_back(stmt);
                        CurrentToken = Lex.GetToken();
                    }
                    else
                    {
                        std::cout << "[Parser] Missing ; after statement. Quitting. " << std::endl;
                        return nullptr;
                    }
                }
                break;
            }
		}
	}
	std::cout << "[Parser] Finished with " << functions->size() << " functions and " << main_impl->size() << " statements parsed." <<std::endl;
    ASTProgramNode * programNode = new ASTProgramNode();
    programNode->functions = functions;
    programNode->main_impl = main_impl;
	return programNode;
}

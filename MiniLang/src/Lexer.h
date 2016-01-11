/*
 * Lexer.h
 *
 *  Created on: Dec 11, 2015
 *      Author: sandro
 */

#ifndef LEXER_H_
#define LEXER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> /* atof() */

class Lexer
{

public:
	Lexer(std::string p_fileName);
	virtual ~Lexer();

	enum TOK_TYPE { TOK_EOF = -1, TOK_DEF = -2, TOK_EXTERN = -3, TOK_ID = -4,
					TOK_NUMBER = -5, TOK_NUM_ERROR = -6, TOK_IF = -7, TOK_PUNC = -8,
					TOK_SRCLANG_TYPE = -9, TOK_SYNTAX_ERR = -10, TOK_BOOLOP = -11,
					TOK_ASSIGNOP = -12, TOK_ARITHMETICOP = -13 };

	struct Token
	{
		TOK_TYPE token_type;
		std::string id_name;
		float number_value;

		Token()
		{
			token_type = TOK_EOF;
			id_name = "";
			number_value = 0;
		}

		Token(TOK_TYPE p_token_type, std::string p_id_name, float p_number_value)
		{
			token_type = p_token_type;
			id_name = p_id_name;
			number_value = p_number_value;
		}

		Token(TOK_TYPE p_token_type)
		{
			token_type = p_token_type;
			id_name = "";
			number_value = 0;
		}

		Token(TOK_TYPE p_token_type, std::string p_id_name)
		{
			token_type = p_token_type;
			id_name = p_id_name;
			number_value = 0;
		}

		Token(TOK_TYPE p_token_type, float p_number_value)
		{
			token_type = p_token_type;
			id_name = "";
			number_value = p_number_value;
		}

		std::string ToString()
		{
			switch (token_type)
			{
				case TOK_EOF : return "[TOK_EOF]";
				case TOK_DEF : return "[TOK_DEF]";
				case TOK_EXTERN : return "[TOK_EXTERN]";
				case TOK_ID : return "[TOK_ID " + id_name + "]";
				case TOK_NUMBER : return "[TOK_NUMBER " + std::to_string(number_value) + "]";
				case TOK_NUM_ERROR : return "[TOK_NUM_ERROR]";
				case TOK_IF : return "[TOK_IF]";
				case TOK_PUNC : return "[TOK_PUNC " + id_name+ "]";
				case TOK_SRCLANG_TYPE : return "[TOK_SRCLANG_TYPE::" + id_name+ "]";
				case TOK_SYNTAX_ERR : return "[TOK_SYNTAX_ERR]";
				case TOK_BOOLOP : return "[TOK_BOOLOP " + id_name+ "]";
				case TOK_ASSIGNOP : return "[TOK_ASSIGNOP]";
				case TOK_ARITHMETICOP : return "[TOK_ARITHMETICOP " + id_name+ "]";
				default : return "ERROR";
			}
		}

	};

	Token GetToken();
	std::string ToString();

private:
	std::string m_inputProgram;
	int m_charIndex;
	int m_lineNumber;

};

#endif /* LEXER_H_ */

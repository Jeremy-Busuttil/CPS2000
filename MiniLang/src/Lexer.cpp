/*
 * Lexer.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: sandro
 */

#include "Lexer.h"

Lexer::Lexer(std::string p_fileName) {
	//Read program from file
	std::cout << "[Lexer] Loading program from " << p_fileName << std::endl;
	std::ifstream programFile;
	programFile.open(p_fileName.c_str());
	m_inputProgram = "";
	if (programFile.is_open())
	{
		std::cout << "[Lexer] Reading program text ... ";
		std::string line;
		while (std::getline(programFile, line))
		{
			m_inputProgram.append(line + '\n');
		}
		std::cout << "done." << std::endl;
	}
	else
	{
		std::cout << "[Lexer] File does not exist!!" << std::endl;
	}
	programFile.close();

	m_charIndex = 0;
	m_lineNumber = 1;
}

Lexer::~Lexer() {
	// TODO Auto-generated destructor stub
}

//Read through m_inputProgram, update state and return the next token
Lexer::Token Lexer::GetToken() {

	//std::cout << m_charIndex << " -- " << m_inputProgram.length() << std::endl;
	if ((unsigned int) m_charIndex == m_inputProgram.length()-1) return Lexer::Token(TOK_EOF);

	char lastChar = m_inputProgram[m_charIndex];

	while (lastChar == ' ' || lastChar == '\n')
	{
		if (lastChar == '\n') m_lineNumber ++;
		m_charIndex ++;
		lastChar = m_inputProgram[m_charIndex];
	}

	//Are these comments?
	if (lastChar == '/')
	{
		m_charIndex ++;
		lastChar = m_inputProgram[m_charIndex];
		if (lastChar == '/')
		{
			//Discard until \n character
			while (lastChar != '\n')
			{
				m_charIndex ++;
				lastChar = m_inputProgram[m_charIndex];
			}
			m_lineNumber ++;

			return GetToken();
		}
		else
		{
			Lexer::Token(TOK_SYNTAX_ERR);
		}
	}

	//Check for punctuation
	if (lastChar == ';')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_PUNC);
		t.id_name = ";";
		return t;
	}

	if (lastChar == ',')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_PUNC);
		t.id_name = ",";
		return t;
	}

	if (lastChar == '(')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_PUNC);
		t.id_name = "(";
		return t;
	}

	if (lastChar == ')')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_PUNC);
		t.id_name = ")";
		return t;
	}

	if (lastChar == '{')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_PUNC);
		t.id_name = "{";
		return t;
	}

	if (lastChar == '}')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_PUNC);
		t.id_name = "}";
		return t;
	}

	//Check for binary operators ==, <, >, <=, >= and assignment operator =
	//Boolean
	if (lastChar == '=')
	{
		m_charIndex ++;
		lastChar = m_inputProgram[m_charIndex];

		if (lastChar == '=')
		{
			m_charIndex ++;
			Lexer::Token t = Lexer::Token(TOK_BOOLOP);
			t.id_name = "==";
			t.number_value = 10; // use to store precedence
			return t;
		} else {
			return Lexer::Token(TOK_ASSIGNOP);
		}
	}

	if (lastChar == '<')
	{
		m_charIndex ++;
		lastChar = m_inputProgram[m_charIndex];
		if (lastChar == '=')
		{
			m_charIndex ++;
			Lexer::Token t = Lexer::Token(TOK_BOOLOP);
			t.id_name = "<=";
			t.number_value = 10; // use to store precedence
			return t;
		}
		else
		{
			Lexer::Token t = Lexer::Token(TOK_BOOLOP);
			t.id_name = "<";
			t.number_value = 10; // use to store precedence
			return t;
		}
	}

	if (lastChar == '>')
	{
		m_charIndex ++;
		lastChar = m_inputProgram[m_charIndex];
		if (lastChar == '=')
		{
			m_charIndex ++;
			Lexer::Token t = Lexer::Token(TOK_BOOLOP);
			t.id_name = ">=";
			t.number_value = 10; // use to store precedence
			return t;
		}
		else
		{
			Lexer::Token t = Lexer::Token(TOK_BOOLOP);
			t.id_name = ">";
			t.number_value = 10; // use to store precedence
			return t;
		}
	}

	//Arithmetic
	if (lastChar == '+')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_ARITHMETICOP);
		lastChar = m_inputProgram[m_charIndex];
		if (lastChar == '+')
		{
			m_charIndex ++;
			t.id_name = "++";
			return t;
		} else {
			t.id_name = "+";
			t.number_value = 20; // use to store precedence
			return t;
		}
	}

	if (lastChar == '-')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_ARITHMETICOP);
		lastChar = m_inputProgram[m_charIndex];
		if (lastChar == '-')
		{
			m_charIndex ++;
			t.id_name = "--";
			return t;
		} else {
			t.id_name = "-";
			t.number_value = 20; // use to store precedence
			return t;
		}
	}

	if (lastChar == '*')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_ARITHMETICOP);
		t.id_name = "*";
		t.number_value = 40; // use to store precedence
		return t;
	}

	if (lastChar == '\\')
	{
		m_charIndex ++;
		Lexer::Token t = Lexer::Token(TOK_ARITHMETICOP);
		t.id_name = "\\";
		t.number_value = 40; // use to store precedence
		return t;
	}

	//Does the input hold an identifier?
	if (std::isalpha(lastChar))
	{
		std::string idStr; idStr += lastChar;
		m_charIndex ++;
		lastChar = m_inputProgram[m_charIndex];
		while (std::isalpha(lastChar))
		{
			idStr += lastChar;
			m_charIndex ++;
			lastChar = m_inputProgram[m_charIndex];
		}

		if (idStr.compare("def")==0)
		{
			return Lexer::Token(TOK_DEF);
		}

		if (idStr.compare("if")==0)
		{
			return Lexer::Token(TOK_IF);
		}

		if (idStr.compare("int")==0)
		{
			return Lexer::Token(TOK_SRCLANG_TYPE);
		}

		//If none of the above, the it must be an identifier
		Lexer::Token t = Lexer::Token(TOK_ID);
		t.id_name = idStr;
		return t;
	}

	//Does the input hold a number?
	if (std::isdigit(lastChar) || lastChar == '.')
	{
		std::string numStr; numStr += lastChar;
		m_charIndex ++;
		lastChar = m_inputProgram[m_charIndex];
		while (std::isdigit(lastChar) || lastChar == '.')
		{
			numStr += lastChar;
			m_charIndex ++;
			lastChar = m_inputProgram[m_charIndex];
		}

		bool validNumber = true;
		int dotCount = 0;
		for (unsigned int i = 0; i<numStr.length(); i++)
		{
			if (numStr[i] == '.') dotCount++;
			if (dotCount > 1) { validNumber = false; break; }
		}

		if (validNumber)
		{
			Lexer::Token t = Lexer::Token(TOK_NUMBER);
			t.number_value = atof(numStr.c_str());
			return t;
		}
		else
		{
			return Lexer::Token(TOK_NUM_ERROR);
		}
	}

	return Lexer::Token(TOK_SYNTAX_ERR);
}

std::string Lexer::ToString() {
	return "[Lexer] Program == " + m_inputProgram;
}

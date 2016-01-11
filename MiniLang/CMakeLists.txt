cmake_minimum_required(VERSION 3.3)
project(CPS2000_MiniLang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/ASTBinaryExprNode.cpp
        src/ASTBinaryExprNode.h
        src/ASTCallExprNode.cpp
        src/ASTCallExprNode.h
        src/ASTExprNode.cpp
        src/ASTExprNode.h
        src/ASTFuncPrototypeNode.cpp
        src/ASTFuncPrototypeNode.h
        src/ASTFunctionNode.cpp
        src/ASTFunctionNode.h
        src/ASTNode.cpp
        src/ASTNode.h
        src/ASTNumberExprNode.cpp
        src/ASTNumberExprNode.h
        src/ASTVariableExprNode.cpp
        src/ASTVariableExprNode.h
        src/CPS2000-LLVM_Project.cpp
        src/Lexer.cpp
        src/Lexer.h
        src/Parser.cpp
        src/Parser.h
        src/ASTStatementNode.cpp
        src/ASTStatementNode.h src/ASTIfStatementNode.cpp src/ASTIfStatementNode.h src/ASTAssignmentStatementNode.cpp src/ASTAssignmentStatementNode.h)

add_executable(CPS2000_MiniLang ${SOURCE_FILES})
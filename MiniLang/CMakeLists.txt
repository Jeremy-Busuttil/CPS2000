cmake_minimum_required(VERSION 3.3)
project(CPS2000_MiniLang)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

set(SOURCE_FILES
        src/ASTNode.cpp
        src/ASTNode.h
        src/ASTBinaryExprNode.cpp
        src/ASTBinaryExprNode.h
        src/ASTCallExprNode.cpp
        src/ASTCallExprNode.h
        src/ASTExprNode.cpp
        src/ASTExprNode.h
        src/ASTNumberExprNode.cpp
        src/ASTNumberExprNode.h
        src/ASTVariableExprNode.cpp
        src/ASTVariableExprNode.h
        src/CPS2000-LLVM_Project.cpp
        src/ASTStatementNode.cpp
        src/ASTStatementNode.h
        src/ASTIfStatementNode.cpp
        src/ASTIfStatementNode.h
        src/ASTAssignmentStatementNode.cpp
        src/ASTAssignmentStatementNode.h
        src/ASTFuncPrototypeNode.cpp
        src/ASTFuncPrototypeNode.h
        src/ASTFunctionNode.cpp
        src/ASTFunctionNode.h
        src/Lexer.cpp
        src/Lexer.h
        src/Parser.cpp
        src/Parser.h src/Visitor.h src/PrintInfoVisitor.cpp src/PrintInfoVisitor.h src/IRCodeGeneratorVisitor.cpp src/IRCodeGeneratorVisitor.h src/ASTReturnStatementNode.cpp src/ASTReturnStatementNode.h src/ASTProgramNode.cpp src/ASTProgramNode.h src/ASTDeclarationStatementNode.cpp src/ASTDeclarationStatementNode.h)

add_executable(CPS2000_MiniLang ${SOURCE_FILES})

# Find the libraries that correspond to the LLVM components that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(CPS2000_MiniLang ${llvm_libs})
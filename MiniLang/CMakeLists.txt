cmake_minimum_required(VERSION 3.3)
project(CPS2000_MiniLang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread")
set(LLVM_INCLUDE_DIRS /usr/lib/llvm-3.7/include/)

set(LLVM_LINK_DIRS /usr/lib/llvm-3.7/lib/)

include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LINK_DIRS})

link_libraries(libLLVMCore.a libLLVMCodeGen.a libLLVMAnalysis.a libLLVMOption.a libLLVMSupport.a libLLVMObject.a libLLVMSelectionDAG.a libLLVMMC.a libLLVMTarget.a
                libLLVMBitReader.a libLLVMBitWriter.a)

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
        src/Parser.h)

add_executable(CPS2000_MiniLang ${SOURCE_FILES})
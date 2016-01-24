//
// Created by sandro on 1/24/16.
//

#include "ASTProgramNode.h"

ASTProgramNode::ASTProgramNode() {
    // TODO Auto-generated constructor stub
}

ASTProgramNode::~ASTProgramNode() {
    // TODO Auto-generated destructor stub
}

void ASTProgramNode::PrintInfo(int p_level) {
    std::cout << "ASTProgramNode []" <<std::endl;
}

void ASTProgramNode::Accept(Visitor *v) {
    v->visit(this);
}

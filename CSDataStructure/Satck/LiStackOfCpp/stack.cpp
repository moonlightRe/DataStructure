#include <cassert>
#include "stack.hpp"

Stack::Stack() {
    //将栈置为空栈
    stack = nullptr;
}

Stack::~Stack() {
    if (stack != nullptr) {
        StackNode *temp = stack;
        stack = stack->next;
        delete (temp);
    }
}

bool Stack::Empty() {
    return stack == nullptr;
}

void Stack::Push(ElemType x) {
    //申请节点
    auto *node = new StackNode(x);
    node->next = stack;
    stack = node;
}

void Stack::Pop() {
    assert(stack != nullptr);
    StackNode *cur = stack;
    stack = stack->next;
    delete (cur);
}

ElemType Stack::GetTop() {
    assert(stack != nullptr);
    return stack->data;
}


StackNode::StackNode(ElemType x) {
    data = x;
    next = nullptr;
}

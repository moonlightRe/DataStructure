#include <cstdlib>
#include "stack.h"

void InitStack(LiStack &stack) {
    //头指针指向nullptr即为空栈
    stack = nullptr;
}

bool StackEmpty(const LiStack &stack) {
    //判断头指针是否指向nullptr
    return stack == nullptr;
}

bool Push(LiStack &stack, ElemType x) {
    //进栈先开辟空间
    auto *node = (LinkNode *) malloc(sizeof(LinkNode));
    if (node == nullptr) return false;
    //赋值
    stack->data = x;
    //进栈
    node->next = stack;
    stack = node;
    return true;
}

bool Pop(LiStack &stack, ElemType &x) {
    //先判空
    if (StackEmpty(stack)) return false;
    //相当于删除第一个节点即可 注意释放空间
    LinkNode *temp = stack;
    stack = stack->next;
    free(temp);
    return true;
}

bool GetTop(const LiStack &stack, ElemType &x) {
    //要取值先判空
    if (StackEmpty(stack)) return false;
    //栈顶就是第一个节点的数据
    x = stack->data;
    return true;
}

void DestoryStack(LiStack &stack) {
    //由于使用malloc开辟空间 销毁需要释放
    if (stack != nullptr) {
        LinkNode *cur = stack;
        LinkNode *temp = nullptr;
        while (cur != nullptr) {
            temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
}

#ifndef SATCK_STACK_HPP
#define SATCK_STACK_H

#include <cstdio>

//链式栈（C语言实现 使用C++引用）
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} *LiStack;

//初始化空栈
void InitStack(LiStack &stack);

//判空
bool StackEmpty(const LiStack &stack);

//进栈
bool Push(LiStack &stack, ElemType x);

//出栈
bool Pop(LiStack &stack, ElemType &x);

//读取栈顶元素
bool GetTop(const LiStack &stack, ElemType &x);

//销毁栈
void DestoryStack(LiStack &stack);

#endif //SATCK_STACK_HPP

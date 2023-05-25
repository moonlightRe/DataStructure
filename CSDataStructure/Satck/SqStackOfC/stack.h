#ifndef SATCK_STACK_H
#define SATCK_STACK_H

#include <cstdio>

//定义栈中元素最大个数
#define MaxSize 50

//顺序栈（C语言实现 使用C++引用）
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];     //存放栈元素的数组
    size_t top;                 //栈顶指针
} SqStack;

//初始化空栈
void InitStack(SqStack &stack);

//栈判空
bool StackEmpty(const SqStack &stack);

//进栈
bool Push(SqStack &stack, ElemType x);

//出栈
bool Pop(SqStack &stack, ElemType &x);

//读取栈顶元素
bool GetTop(const SqStack &stack, ElemType &x);

//销毁栈
void DestoryStack(SqStack &stack);

#endif //SATCK_STACK_H

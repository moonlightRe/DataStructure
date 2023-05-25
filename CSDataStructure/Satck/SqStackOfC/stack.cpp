#include "stack.h"

void InitStack(SqStack &stack) {
    //data数组无需初始化 内部数据使用时覆盖 不使用时不会访问
    stack.top = -1;
}

bool StackEmpty(const SqStack &stack) {
    //若top栈顶指针的值为-1表明为空栈
    return stack.top == -1;
}

bool Push(SqStack &stack, ElemType x) {
    //判断栈是否满
    if (stack.top == MaxSize - 1) return false;

    //有余量则进栈 先将top++再插入数据
    stack.data[++stack.top];
    return true;
}

bool Pop(SqStack &stack, ElemType &x) {
    //判断栈是否为空
    if (StackEmpty(stack)) return false;

    //有余量则出栈操作 先传递数据再将top--
    x = stack.data[stack.top--];
    return true;
}

bool GetTop(const SqStack &stack, ElemType &x) {
    //栈为空无法获取栈顶元素
    if (StackEmpty(stack)) return false;

    //有数据则将将栈顶元素传递即可
    x = stack.data[stack.top];
    return true;
}

void DestoryStack(SqStack &stack) {
    //销毁栈将top设置为-1即可
    //使其访问不到栈中被覆盖的数据即可
    stack.top = -1;
}


#ifndef SATCK_STACK_HPP
#define SATCK_STACK_HPP

#include <cstdio>
//定义栈的最大空间
#define MaxSize 50

template<class T>
class stack {
private:
    T data[MaxSize];
    size_t top = -1;

public:
    //构造函数
    stack();

    //使用系统生成的析构函数即可

    //判空
    bool Empty();

    //进栈
    bool Push(T x);

    //出栈
    bool Pop();

    //获取栈顶元素
    T &GetTop();
};

template<class T>
T &stack<T>::GetTop() {
    if (Empty()) return false;
    return data[top];
}

template<class T>
bool stack<T>::Pop() {
    //判空
    if (Empty()) return false;
    top--;
}

template<class T>
bool stack<T>::Push(T x) {
    //检查容量
    if (top == MaxSize - 1) return false;
    data[++top] = x;
    return true;
}

template<class T>
stack<T>::stack() {
    //初始化栈顶指针
    top = -1;
}

template<class T>
bool stack<T>::Empty() {
    return top == -1;
}

#endif //SATCK_STACK_HPP

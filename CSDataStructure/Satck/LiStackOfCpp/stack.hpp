
#ifndef SATCK_STACK_HPP
#define SATCK_STACK_HPP


typedef int ElemType;

//栈节点定义
class StackNode {
    friend class Stack;

    ElemType data;
    StackNode *next;
public:
    //构造函数
    explicit StackNode(ElemType x);
};

//栈定义（不带头节点）
class Stack {
private:
    StackNode *stack;
public:
    //构造函数
    Stack();

    //析构函数
    ~Stack();

    //判空
    bool Empty();

    //进栈
    void Push(ElemType x);

    //出栈
    void Pop();

    //读取栈顶元素
    ElemType GetTop();
};


#endif //SATCK_STACK_HPP
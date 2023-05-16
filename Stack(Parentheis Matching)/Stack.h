#ifndef STACK_STACK_H
#define STACK_STACK_H

class Stack{
    char* _array;
    //栈顶
    int _top{};
    //容量
    int _capacity{};

public:
    void Push(char ch);

    void Pop();

    [[nodiscard]] int Size() const;

    [[nodiscard]] bool Empty() const;

    char Top();

    void Dilatation();

    explicit Stack(int capacity);

    ~Stack();
};
#endif

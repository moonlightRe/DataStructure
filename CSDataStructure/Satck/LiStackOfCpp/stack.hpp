
#ifndef SATCK_STACK_HPP
#define SATCK_STACK_HPP



template<class T>
class Stack{
private:
    T data;
    Stack* next;
public:
    //构造函数
    Stack();
};

template<class T>
Stack<T>::Stack() {
    //生成空栈

}


#endif //SATCK_STACK_HPP
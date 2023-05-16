#include <cstdlib>
#include <cassert>
#include"Stack.h"

//Stack构造函数
Stack::Stack(int capacity) {
    //开辟栈空间
    _array = (char*)malloc(sizeof(char) * capacity);
    if(_array){
        _top = -1;
        _capacity = capacity;
        return;
    }
    else{
        //开辟栈空间失败
        perror("_array malloc fail");
        exit(-1);
    }
}

//Stack析构函数
Stack::~Stack() {
    //若malloc开辟的空间不为nullptr则进行释放
    if(!_array){
        free(_array);
        _capacity = 0;
        _top = -1;
    }
}

//进栈函数
void Stack::Push(char ch) {
    if(_top == _capacity - 1)
        //判断栈空间是否已满，满则扩容
        Dilatation();

    //进行数据插入更新操作
    _top++;
    _array[_top] = ch;
}

//出栈函数
void Stack::Pop() {
    //若栈中无数据无法进行删除
    assert(!Empty());
    _top--;
}

//栈数据个数
int Stack::Size() const {
    return _top + 1;
}

//判空
bool Stack::Empty() const {
    return _top == -1;
}

//获取栈顶元素
char Stack::Top() {
    assert(!Empty());
    return _array[_top];
}

//开辟堆空间
void Stack::Dilatation() {
    //尝试开辟栈新空间
    int newCapacity = _capacity * 2;
    char* newArray = (char*) realloc(_array, newCapacity * sizeof(char));
    //判断是否开辟成功
    if(newArray){
        //开辟成功则更新指针和容量
        _array = newArray;
        _capacity = newCapacity;
    }
    else{
        perror("newArray realloc fail");
        exit(-1);
    }
}
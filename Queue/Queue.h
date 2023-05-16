#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

//便于后续数据类型更改
//后续可以使用模板优化
typedef int QDataType;

class QNode{
public:
    QNode* _next;
    QDataType _data;
};

class Queue{
private:
    QNode* _head;
    QNode* _tail;
public:
    Queue();
    ~Queue();
    void Push(QDataType x);
    void Pop();
    QDataType Front();
    QDataType Back();
    bool Empty();
    int Size();
};

#endif

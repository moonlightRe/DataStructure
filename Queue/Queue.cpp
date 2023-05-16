#include <cstdlib>
#include <cassert>
#include"Queue.h"

Queue::Queue() {
    _head = _tail = nullptr;
}

Queue::~Queue() {
    QNode* cur = _head;
    while(cur){
        QNode* del = cur;
        cur = cur->_next;
        free(del);
    }
    _head = _tail = nullptr;
}

void Queue::Push(QDataType x) {
    QNode *newNode;
    newNode = (QNode *) malloc(sizeof(QNode));

    if(newNode == nullptr){
        perror("malloc fail");
        exit(-1);
    }
    else{
        newNode->_data = x;
        newNode->_next = nullptr;
    }

    if(_head == nullptr){
        _head = _tail = newNode;
    }
    else{
        _tail->_next = newNode;
        _tail = _tail->_next;
    }
}

void Queue::Pop() {
    //assert(_head);
    assert(!Empty());
    QNode* temp = _head;
    if(_head == _tail){
        free(_head);
        _head = _tail = nullptr;
        return;
    }
    _head = _head->_next;
    free(temp);
}

QDataType Queue::Front() {
    assert(!Empty());
    return _head->_data;
}

QDataType Queue::Back() {
    assert(!Empty());
    return _tail->_data;
}

bool Queue::Empty() {
    return _head == nullptr;
}

int Queue::Size() {
    int cnt = 0;
    while(_head <= _tail){
        _head++;
        _tail--;
        if(_head == _tail)
            cnt++;
        else
            cnt += 2;
    }
    return cnt;
}

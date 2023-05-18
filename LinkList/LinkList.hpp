#ifndef LINKLIST_LINKLIST_HPP
#define LINKLIST_LINKLIST_HPP

#include<iostream>
using namespace std;

template<class T>
class LinkListNode {
private:
    T _data;
    LinkListNode *_next;
public:
    LinkListNode() {
        _next = nullptr;
    }

    //TODO 存在问题
    //malloc新节点
    LinkListNode* buyNode(const T& x){
        auto* newNode = (LinkListNode*)malloc(sizeof(LinkListNode));
        if(newNode){
            newNode->_data = x;
            newNode->_next = nullptr;
            return newNode;
        }else{
            perror("malloc fail");
            exit(-1);
        }
    }

    //尾插
    void push_back(const T& x){
        //auto* newNode = (LinkListNode*)malloc(sizeof(LinkListNode));
        auto* newNode = buyNode(x);
        //newNode->_data = x;
        LinkListNode* temp = this;
        //找到尾节点
        while(temp->_next != nullptr){
            temp = temp->_next;
        }
        temp->_next = newNode;
        newNode->_next = nullptr;
    }

    //头插
    void push_front(const T& x){
        auto* newNode = (LinkListNode*)malloc(sizeof(LinkListNode));
        newNode->_data = x;
        newNode->_next = this->_next;
        this->_next = newNode;
    }

    //尾删
    void pop_back(){
        assert(this->_next != nullptr);
        LinkListNode* temp = this;
        //寻找倒数第二个节点
        while(temp->_next->_next != nullptr){
            temp = temp->_next;
        }
        temp->_next = nullptr;
    }

    //头删
    void pop_front(){
        assert(this->_next != nullptr);
        LinkListNode* temp = this;
        this->_next = this->_next->_next;
    }

    //打印
    void print(){
        //assert(this->_next != nullptr);
        LinkListNode* temp = this;
        while(temp != nullptr){
            if(temp != this)
                cout << temp->_data << " ";
            temp = temp->_next;
        }
        cout << "nullptr" << endl;
    }
};



#endif //LINKLIST_LINKLIST_HPP

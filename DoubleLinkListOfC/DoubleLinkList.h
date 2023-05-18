#ifndef DOUBLELINKLISTOFC_DOUBLELINKLIST_H
#define DOUBLELINKLISTOFC_DOUBLELINKLIST_H

#include<iostream>
#include <cassert>
using namespace std;

//带头双向循环链表
typedef int LinkDataType;
struct LinkListNode{
    LinkDataType _data;
    struct LinkListNode* _next;
    struct LinkListNode* _prev;
};

//创建链表返回头节点
LinkListNode* LinkListInit(){
    auto* headNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    if(headNode){
        //初始化头节点的头尾指针均指向自身
        headNode->_next = headNode;
        headNode->_prev = headNode;
        return headNode;
    }
    else{
        perror("malloc headNode fail");
        exit(-1);
    }
}

//双向链表销毁
void LinkListDestory(LinkListNode* plist){
    assert(plist);
    //节点指针cur指向头节点的下一个
    LinkListNode* cur = plist->_next;
    LinkListNode* temp = nullptr;
    while(cur != nullptr){
        temp = cur;
        cur = cur->_next;
        free(temp);
    }
}

//双向链表打印
void LinkListPrint(LinkListNode* plist){
    assert(plist);
    LinkListNode* cur = plist->_next;
    cout << "headNode-> ";
    while(cur != plist){
        cout << cur->_data << "-> ";
        cur = cur->_next;
    }
}

//插入节点时创建新节点
LinkListNode* buyNode(LinkDataType x){
    auto* newNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    if(newNode){
        newNode->_data = x;
        newNode->_next = nullptr;
        newNode->_prev = nullptr;
        return newNode;
    }
    else{
        perror("malloc newNode fail");
        exit(-1);
    }
}

//双向链表尾插
void LinkListPushBack(LinkListNode* plist, LinkDataType x){
    assert(plist);
    LinkListNode* newNode = buyNode(x);
    //先找到尾节点
    //头节点的头指针指向尾节点
    LinkListNode* tail = plist->_prev;
    //让原来尾节点的尾指针指向新节点 头指针的头节点指向新节点
    //新节点的头指针指向原来的尾节点 新节点的尾指针指向头节点
    tail->_next = newNode;
    plist->_prev = newNode;
    newNode->_prev = tail;
    newNode->_next = plist;
}

//双向链表尾删
void LinkListPopBack(LinkListNode* plist){
    assert(plist);
    //没有节点不能删除
    assert(plist->_next != plist);
    //先取到尾节点
    LinkListNode* tail = plist->_prev;
    //再取尾节点的上个节点
    LinkListNode* tail_prev = tail->_prev;
    //再将尾节点的前节点与头节点对接
    tail_prev->_next = plist;
    plist->_prev = tail_prev;
    //malloc的空间需要释放
    free(tail);
}

//双向链表头插
void LinkListPushFront(LinkListNode* plist, LinkDataType x){
    assert(plist);
    //取到第一个节点
    LinkListNode* cur = plist->_next;
    //新节点
    LinkListNode* newNode = buyNode(x);
    //将头节点、第一个节点和新节点连接
    plist->_next = newNode;
    cur->_prev = newNode;
    newNode->_prev = plist;
    newNode->_next = cur;
}

//双向链表头删
void LinkListPopFront(LinkListNode* plist){
    assert(plist);
    if(plist->_next == plist){
        perror("NO NODE");
        exit(-1);
    }
    //取到第一个节点的下一个节点
    LinkListNode* second = plist->_next->_next;
    //将头节点和second节点连接
    plist->_next = second;
    second->_prev = plist;
}

//双向链表查找
LinkListNode* LinkListFind(LinkListNode* plist, LinkDataType x){
    assert(plist);
    LinkListNode* cur = plist->_next;
    while(cur != plist){
        if(cur->_data == x){
            return cur;
        }
        cur = cur->_next;
    }
    //不存在
    return nullptr;
}

//双向链表在pos位置前面插入
void LinkListInsert(LinkListNode* plist,LinkListNode* pos, LinkDataType x){
    assert(plist);
    //若等于头指针则尾插
    if(pos == plist)
        LinkListPushBack(plist, x);

    LinkListNode* cur = plist->_next;
    while(cur != plist){
        if(pos == cur){
            LinkListNode* newNode = buyNode(x);
            LinkListNode* prev = cur->_prev;
            //将前节点、pos节点与新节点连接
            prev->_next = newNode;
            cur->_prev = newNode;
            newNode->_prev = prev;
            newNode->_next = cur;
        }
        cur = cur->_next;
    }
    //若不存在此节点
    perror("this node is illegal");
    exit(-1);
}

//双向链表删除pos位置的节点
void LinkListErase(LinkListNode* plist, LinkListNode* pos){
    assert(plist);
    assert(pos && pos != plist);

    LinkListNode* cur = plist->_next;
    while(cur != plist){
        if(cur == pos){
            LinkListNode* prev = cur->_prev;
            LinkListNode* next = cur->_next;
            //连接前后节点
            prev->_next = next;
            next->_prev = prev;
            free(cur);
            return;
        }
        cur = cur->_next;
    }
    //若不存在此节点
    perror("this node is illegal");
    exit(-1);
}

#endif //DOUBLELINKLISTOFC_DOUBLELINKLIST_H
#ifndef LINKLISTOFC_LINKLIST_HPP
#define LINKLISTOFC_LINKLIST_HPP

#include<iostream>
#include<cstdlib>
#include <cassert>

using namespace std;

//实现不带头结点的单向链表
typedef int LinkDataType;
typedef struct LinkListNode{
    LinkDataType _data;
    struct LinkListNode* _next;
}LinkList;

//创建节点
LinkListNode* buyNode(LinkDataType x){
    auto* newNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    if(newNode == nullptr){
        perror("malloc fail");
        exit(-1);
    }
    newNode->_data = x;
    newNode->_next = nullptr;
    return newNode;
}

//打印
void LinkListPrint(LinkList* linkList){
    LinkListNode* cur = linkList;
    while(cur != nullptr){
        cout << cur->_data << " ";
        cur = cur->_next;
    }
    cout << "nullptr" << endl;
}

//头插
void LinkListPushFront(LinkList** pLinkList, LinkDataType x){
    assert(pLinkList);
    //拿到头指针内存的地址值(为空或指向第一个结点)
    LinkListNode* cur = *pLinkList;
    //新节点
    LinkListNode* newNode = buyNode(x);
    if(cur == nullptr){
        newNode->_next = nullptr;
        cur = newNode;
        *pLinkList = cur;
        return;
    }
    newNode->_next = cur;
    cur = newNode;
    *pLinkList = cur;
}

//尾插
void LinkListPushBack(LinkList** pLinkList, LinkDataType x){
    assert(pLinkList);
    LinkListNode* cur = *pLinkList;
    LinkListNode* newNode = buyNode(x);

    //链表为空，即头指针为空的情况
    if(cur == nullptr){
        newNode->_next = cur;
        cur = newNode;
        *pLinkList = cur;
        return;
    }

    //若不为空则需要找到最后一个节点
    while(cur->_next != nullptr){
        cur = cur->_next;
    }

    //此时cur指向最后一个节点
    //不用*pLinkList的原因是当前情况不需要改变头指针的指向
    newNode->_next = cur->_next;
    cur->_next = newNode;
}

//头删
void LinkListPopFront(LinkList** pLinkList){
    //头指针的指针一定不为空所以断言
    assert(pLinkList);
    //删除的话链表不能为空
    assert(*pLinkList);

    //取到头节点的副本
    LinkListNode* cur = *pLinkList;
    //将头节点指向第一个节点的_next即第二个节点或者nullptr
    cur = cur->_next;
    *pLinkList = cur;
}

//尾删
void LinkListPopBack(LinkList** pLinkList){
    assert(pLinkList);
    assert(*pLinkList);

    LinkListNode* cur = *pLinkList;
    //找到最后一个节点无用因为无法得到它前一个节点的指针
    //所以必须拿到倒数第二个节点的指针

    //如果使用cur->_next->_next的话，只有一个节点的情况会报错
    //若只有一个节点直接将头指针置空即可
    if(cur->_next == nullptr){
        *pLinkList = nullptr;
        return;
    }
    //普遍情况
    while(cur->_next->_next != nullptr){
        cur = cur->_next;
    }
    //找到倒数第二个节点使其_next为nullptr变为尾节点即可
    //但是在这之前需要free尾节点，否则造成内存泄露
    free(cur->_next);
    cur->_next = nullptr;
}

//查找
LinkListNode* LinkListFind(LinkList* list, LinkDataType x){
    //链表为空无法查找
    assert(list != nullptr);

    //使用LinkListNode* cur更加突出节点指针的含义
    LinkListNode* cur = list;

    //遍历查找每一个节点的值
    while(cur != nullptr){
        if(cur->_data == x){
            return cur;
        }
        cur = cur->_next;
    }
    return nullptr;
}

// 单链表在pos位置之后插入x
/*TODO 分析思考为什么不在pos位置之前插入？
 *
 * 因为单向不循环链表无法向前遍历，或许可以用一个结点指针一直保存前面一个节点的指针实现前插
 * 或者可以创建出一个新节点在pos之后，将x插入新节点，将pos和新节点的值互换，但是会改变节点的地址值
 *
*/
void LinkListInsertAfter(LinkList** pLinkList,LinkListNode* pos, LinkDataType x){
    assert(pLinkList);
    LinkListNode* cur = *pLinkList;

    //头指针和传入的节点指针均为空，则相当于在头节点后插入(空链表的头插)，调用函数即可
    if(cur == nullptr && pos == nullptr){
        LinkListPushFront(pLinkList, x);
        return;
    }else if(cur != nullptr && pos == nullptr){
        perror("pos should not be nullptr");
        exit(-1);
    }
    //或者不需要if分支，使用assert(pos)延迟判断也可达到相同效果

    //普遍情况
    while(cur != nullptr){
        if(cur == pos){
            //找到此节点
            LinkListNode* newNode = buyNode(x);
            newNode->_next = cur->_next;
            cur->_next = newNode;
            return;
        }
        cur = cur->_next;
    }
    perror("the pos is false!");
    exit(-1);
}

// 单链表删除pos位置之后的值
/* TODO 分析思考为什么不删除pos位置？
 *
 */
void LinkListEraseAfter(LinkList** pLinkList, LinkListNode* pos){
    assert(pLinkList);
    //此情况和删除pos后不同，nullptr无法向后删
    assert(pos);

    //普遍情况
    //最多寻找到倒数第二个节点因为最后一个节点的_next为空不满足循环条件跳出循环并报错
    //同时头指针为空以及pos为空在断言中判断
    //若有一个节点相当于直接不满足循环条件
    //综上所述不需要其他特殊情况的判断和处理
    LinkListNode* cur = *pLinkList;
    while(cur->_next != nullptr){
        if(cur == pos){
            LinkListNode* temp = cur->_next;
            cur->_next = cur->_next->_next;
            free(temp);
            return;
        }
        cur = cur->_next;
    }
    perror("the pos is false!");
    exit(-1);
}

#endif //LINKLISTOFC_LINKLIST_HPP

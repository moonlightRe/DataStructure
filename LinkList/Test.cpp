#include <cassert>
#include"LinkList.hpp"

void Test(){
    //创建链表(头节点)
    LinkListNode<int> linkListNode;

    linkListNode.push_front(3);
    linkListNode.push_front(4);
    linkListNode.push_front(5);

    linkListNode.push_back(7);
    linkListNode.push_back(8);
    linkListNode.print();

}

int main(){

    Test();
    return 0;
}

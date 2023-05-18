#include"DoubleLinkList.h"

int main(){

    //创建头节点并返回头节点指针
    auto* plist = LinkListInit();
    LinkListPushBack(plist, 2);
    LinkListPushBack(plist, 3);
    LinkListPushBack(plist, 4);
    LinkListPushFront(plist, 1);
    //LinkListPopFront(plist);
    LinkListPopBack(plist);
    LinkListPrint(plist);
    LinkListDestory(plist);

    return 0;
}
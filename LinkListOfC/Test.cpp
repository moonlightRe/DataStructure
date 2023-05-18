#include"LinkList.hpp"

int main(){
    LinkList* list = nullptr;
    LinkListPushFront(&list, 2);
    LinkListPushFront(&list, 3);
    LinkListPushBack(&list, 4);

    LinkListPopFront(&list);
    LinkListPrint(list);

    return 0;
}
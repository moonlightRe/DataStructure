#include <iostream>
#include"SqList.h"
int main() {
    SqList sqList;
    sqList.PushBack(1);
    sqList.PushBack(1);
    sqList.PushBack(1);
    sqList.PushBack(1);
    sqList.PushBack(1);
    sqList.PushBack(1);
    sqList.Delete_Same();
    sqList.Print();
    return 0;
}

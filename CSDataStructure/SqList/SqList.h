#ifndef SQLIST_SQLIST_H
#define SQLIST_SQLIST_H

#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;
typedef int ElemType;

//顺序表的动态实现
class SqList {

private:
    //数据空间指针
    ElemType *_data;
    //顺序表元素数量
    size_t _size;
    //顺序表最大容量
    size_t _capacity;
public:

    //基本操作函数
    SqList();

    ~SqList();

    void Capacity();

    [[nodiscard]] bool Empty() const;

    [[nodiscard]] size_t Length() const;

    bool Insert(size_t pos, ElemType e);

    bool Delete(size_t pos, ElemType &e);

    ElemType GetElem(size_t pos);

    size_t FindPos(ElemType e);

    bool PushBack(ElemType e);

    bool PushFront(ElemType e);

    bool PopBack(ElemType &e);

    bool PopFront(ElemType &e);

    void Print();

    //课后练习

    /*①从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除的元素的值
     * 空出的位置由最后一个元素填补，若顺序表为空，则显示出错误信息并退出运行
    */
    bool FindMin(ElemType &e);

    /*②设计一个高效算法，将顺序表逆置，要求算法空间复杂度为O(1)
     */
    void Reverse();

    /*
     * ③对长度为L的顺序表，编写一个时间复杂度度为O(n)、空间复杂度为O(1)的算法
     * 该算法删除线性表中所有值为x的数据元素
     * */
    void Delete_X1(ElemType x);
    void Delete_X2(ElemType x);
    void Delete_X3(ElemType x);

    /*
     * ④从-->有序<--顺序表中删除其值在给定值s与t之间（s<t）的所有元素
     * 若s/t不合理或顺序表为空，则显示错误信息并退出运行
     * */
    void Delete_s_t(size_t s, size_t t);

    /*
     * ⑤
     * */

    /*
     * ⑥从有序顺序表中删除所有值重复的元素，使表中所有元素的值均不同
     * */
    void Delete_Same();


    /*
     * ⑦将两个有序顺序表合并为一个新的有序顺序表，使表中元素的值均不相同
     * */
    bool Merge(SqList& sqList, SqList& newList);
};

#endif //SQLIST_SQLIST_H

#include"SqList.h"

//顺序表初始化（构造函数）
SqList::SqList() {
    _capacity = 4;
    _data = new ElemType[_capacity];
    _size = 0;
}


//清理开辟的空间（析构函数）
SqList::~SqList() {
    delete[] _data;
    _size = 0;
    _capacity = 0;
}


//检查空间容量
void SqList::Capacity() {
    //有容量直接退出
    if (_size < _capacity) return;

    //开辟新空间
    size_t newCapacity = _capacity * 2;
    auto *tempData = new(nothrow) ElemType[newCapacity];
    //判断开辟成功与否
    if (tempData == nullptr) {
        cerr << "Bad Alloc" << endl;
        return;
    }
    //数据迁移
    for (size_t index = 0; index < _size; index++) {
        tempData[index] = _data[index];
    }
    //释放原有空间
    delete[] _data;

    _data = tempData;
    _capacity = newCapacity;
}


//判空函数
bool SqList::Empty() const {
    return _size == 0;
}

//顺序表长度
size_t SqList::Length() const {
    return _size;
}

//向顺序表的pos位置插入数据
//pos的数据类型为pos，因此将其理解为开辟的数组下标
bool SqList::Insert(size_t pos, ElemType e) {
    if (pos > _size) return false;
    //插入需要检查空间
    Capacity();
    //移动并插入数据
    for (size_t index = _size; index > pos; index++) {
        _data[index] = _data[index - 1];
    }
    _data[pos] = e;
    _size++;
    return true;
}


//向顺序表的pos位置删除数据
bool SqList::Delete(size_t pos, ElemType &e) {
    if (pos >= _size) return false;
    //先传递删除数据
    e = _data[pos];
    //挪动数据
    for (size_t index = pos; index < _size - 1; index++) {
        _data[index] = _data[index + 1];
    }
    _size--;
    return true;
}

//查找pos位置的数据
ElemType SqList::GetElem(size_t pos) {
    //断言pos值
    assert(pos < _size);
    return _data[pos];
}

//按值查找
size_t SqList::FindPos(ElemType e) {
    //遍历寻求
    for (size_t index = 0; index < _size; index++) {
        if (_data[index] == e)
            return index;
    }
    //若不存在则返回-1
    return -1;
}

//打印顺序表
void SqList::Print() {
    for (size_t index = 0; index < _size; index++) {
        cout << _data[index] << " ";
    }
}

//尾插
bool SqList::PushBack(ElemType e) {
    return Insert(_size, e);
}

//头插
bool SqList::PushFront(ElemType e) {
    return Insert(0, e);
}

//尾删
bool SqList::PopBack(ElemType &e) {
    return Delete(_size - 1, e);
}

//头删
bool SqList::PopFront(ElemType &e) {
    return Delete(0, e);
}

//寻求最小值
bool SqList::FindMin(ElemType &value) {
    if (_size == 0) return false;
    //假定最小值为第一个元素的值
    value = _data[0];
    size_t pos = 0;
    //遍历寻求（自身无需比较，index从1开始）
    for (size_t index = 1; index < _size; index++) {
        if (_data[index] < value) value = _data[index];
        //更新最小值下标
        pos = index;
    }
    //删除数据并填补
    _data[pos] = _data[_size - 1];
    _size--;
    return true;
}

//逆置顺序表 O(1)空间复杂度
void SqList::Reverse() {
    assert(_size > 0);
    //下标指向
    size_t begin = 0;
    size_t end = _size - 1;
    ElemType temp;
    for (begin, end; begin < end; begin++, end--) {
        //开辟额外一块空间（辅助变量）完成交换
        temp = _data[begin];
        _data[begin] = _data[end];
        _data[end] = temp;
    }

    //更优化的结构
    for (size_t index = 0; index < _size / 2; index++) {
        temp = _data[index];
        _data[index] = _data[_size - 1 - index];
        _data[_size - 1 - index] = temp;
    }

}

//解法一
//遍历顺序表，将不等于x的元素的值从顺序表开头重新填入
//遍历完之后，可能将一部分x值覆盖，但是前面的元素（count）的值都是不等于x的
//再将顺序表的长度改为count即可完成删除
void SqList::Delete_X1(ElemType x) {
    assert(_size > 0);
    size_t count = 0;
    for (size_t index = 0; index < _size; index++) {
        if (_data[index] != x) {
            _data[count] = _data[index];
            count++;
        }
    }
    _size = count;
}

//解法二
void SqList::Delete_X2(ElemType x) {
    assert(_size > 0);
    size_t count = 0;
    for (size_t index = 0; index < _size; index++) {
        if (_data[index] == x)
            count++;
        else
            _data[index - count] = _data[index];
    }
    _size = _size - count;
}

//解法三
void SqList::Delete_X3(ElemType x) {
    assert(_size > 0);
    size_t begin = 0;
    size_t end = _size - 1;
    for (begin, end; begin < end;) {

        if(_data[begin] != x) {
            //begin指向的值若不为x则一定需要保留
            begin++;
            if(_data[end] == x){
                end--;
                _size--;
            }
            else{
                _data[begin] = _data[end];
                end--;
            }
            end--;

        }
    }
}















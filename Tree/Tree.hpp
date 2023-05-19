#ifndef TREE_TREE_HPP
#define TREE_TREE_HPP

#include <iostream>
#include <cstdio>
#include <iostream>
#include <valarray>
#include <cassert>

using namespace std;

//满二叉树下标对应规则
//leftChild = parent * 2 + 1 && rightChild = parent * 2 + 1 + 1;
//parent = ( (leftChild || rightChild) - 1 ) / 2;

//模板堆类的定义
template<class T>
class Tree {
private:

    T *_data;
    size_t _size;
    size_t _capacity;

public:

    //构造函数
    Tree() {
        _data = nullptr;
        _size = _capacity = 0;
    }

    //析构函数
    ~Tree() {
        if (_data) {
            delete[] _data;
            _data = nullptr;
            _size = _capacity = 0;
        }
    }

    //检查容量
    void checkCapacity() {
        if (_size == _capacity) {
            //判断_capacity是否是仅初始化
            size_t tempCapacity = (_capacity == 0) ? 4 : _capacity * 2;
            T *tempData = new T[tempCapacity];
            //TODO memcpy函数使用
            //挪动数据
            for (size_t index = 0; index < _size; index++) {
                tempData[index] = _data[index];
            }
            if (_data != nullptr)
                delete[] _data;
            //判断new空间是否成功（此处似乎无异常抛出机制）
            if (tempData) {
                _data = tempData;
                _capacity = tempCapacity;
            } else {
                perror("New fail!");
                exit(-1);
            }
        }
    }

    //向上调整数据
    void adjustUp() {
        //插入的孩子节点 需要和父节点比较
        size_t child = _size - 1;
        size_t parent = (child - 1) / 2;
        //循环向上遍历比较
        while (child != 0) {
            //只有小于才调整
            //如果等于或者大于那么上面也不与要接着比较（因为上面也是堆的状态）
            if (_data[child] < _data[parent])
                swap(_data[child], _data[parent]);
            else
                return;
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    //插入数据
    void push(const T &x) {
        //插入数据得检查容量（动态）
        checkCapacity();
        _data[_size] = x;
        _size++;
        //向堆中插入数据后需要->向上调整<-保持堆形态
        adjustUp();
    }

    //打印数据
    void print() {
        cout << "size->" << _size << " capacity->" << _capacity << endl;
    }

    //获取堆顶元素
    T top() {
        if (_size > 0)
            return _data[0];
    }


    //向下调整
    void adjustDown() {
        size_t parent = 0;
        size_t minChild = 0 * 2 + 1;
        while (minChild < _size) {
            if (minChild + 1 < _size && _data[minChild + 1] < _data[minChild]) {
                minChild++;
            }
            if (_data[minChild] < _data[parent]) {
                swap(_data[minChild], _data[parent]);
            } else {
                return;
            }
            parent = minChild;
            minChild = parent * 2 + 1;
        }
    }

    //删除堆顶元素
    void pop() {
        assert(!Empty());
        swap(_data[0], _data[_size - 1]);
        _size--;
        //向下调整
        adjustDown();
    }

    //判空
    bool Empty() {
        return _size == 0;
    }
};

#endif //TREE_TREE_HPP

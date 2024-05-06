#ifndef __LIST_HPP__
#define __LIST_HPP__

#include<iostream>
#include<algorithm>

namespace MyAlgorithm
{

    template<typename _Type>
    class List
    {
    public:
        List();
        List(int capacity);
        List(const List &other);
        List(const List &&other);
        List &operator=(const List &other);
        List &operator=(const List &&other);
        ~List();

    private:
        _Type *ptr_;    //存放内存空间
        size_t capacity_; //空间的大小
        size_t length_; //空间中的元素
    }
}

#endif //__LIST_HPP__
/*
1.右值
相对于左值是特殊情况,是不能取地址的

2.万能应用
auto T&& 一个类型推导到右值引用,右值引用能同时兼容左值和右值引用

3.完美转发
利用万能引用作为函数的参数,可能完美转发形参







*/
////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>


using std::cout;
using std::endl;


//1.
void test1();

//2. 
void test2();


int main(){
    return 0;
}
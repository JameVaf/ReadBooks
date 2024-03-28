/*
1.long long
long long 类型,至少是64位,8个字节的大小,long是至少4个字节
使用宏LLONG_MAX 可以得到定义
或者numeric_limits模版结构体 利用模版特化返回信息

2.char16_t char32_t
char16_t char32_t分别表示 utf-16 和 utf-32 编码
wchar_t 类型,宽字节,但是在win10是两个字节 在linux和macos是4个字节
char8_t 是utf-8 编码的字符. c++20的特性




*/

////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<limits>

using std::cout;
using std::endl;
//long long
void test1();

//char8_t 
void test2();

int main(){

test2();


}


//long long
void test1(){
    cout<<"Long Long Max = " << LLONG_MAX<<endl;
    cout<<std::numeric_limits<long long>::max()<<endl;
    struct std::numeric_limits<long long> t;
    long long a = t.max();
    cout<<"long long max  = "<<a <<endl;
}

//char8_t 
void test2(){
    char ch [] = u8"test";
    cout<< ch  <<endl;
}
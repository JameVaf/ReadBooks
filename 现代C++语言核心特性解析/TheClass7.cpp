/*
1.lambda表达式
解决了过去C++中无法直接编写内嵌函数的尴尬。虽然在GCC中提供了
一个叫作nest function的C语言扩展，这个扩展允许我们在函数内部
编写内嵌函数，但这个特性一直没有被纳入标准当中。当然我们也并
不用为此遗憾，因为现在提供的lambda表达式无论在语法简易程度
上，还是用途广泛程度上都要优于nest function。合理地使用lambda
表达式，可以让代码更加短小精悍的同时也具有良好的可读性






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
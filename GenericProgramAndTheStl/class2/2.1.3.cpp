#include<iostream>

using namespace std;

template<class Iterator,class T>
Iterator find2(Iterator first,Iterator end,const T &value )
{
    while (first != end && *first != value)
    {
        first++;
    }
    return first;
    
}
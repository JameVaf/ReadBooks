#include<iostream>



size_t strlen(const char* str)
{
    if(nullptr == str)
    {
        throw std::runtime_error("nullptr exception");
    }
    size_t size = 0;
    while(*(str + size) != '\0')
    {
        size++;
    }
    return size;
}

int main()
{
    std::cout<<strlen("nullptr");
    return 0;
}
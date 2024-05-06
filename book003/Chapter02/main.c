#include "GJ_alloc.h"
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    int ia[5] = {0, 1, 2, 3, 4};
    unsigned int i;

    vector<int, GJ::allocator<int>> iv(ia, ia + 5);
    for(auto iter:iv)
    {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
    return 0;
}
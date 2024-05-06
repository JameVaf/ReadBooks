#include<iostream>
#include<vector>

std::vector<int> Test(const std::vector<int>& input)
{
     std::vector<int> ret, right;
    //首先找到每一个元素右侧最大的值
    int len = (int)input.size();
    int max = 0;
    for (int j = len -1; j >=0;--j)
    {
        if( j == len-1)
        {
            max = input[j];

        }
        else
        {
            if(input[j] > max)
            {
                max = input[j];
            }
        }
        right.push_back(max);
    }
    std::vector<int> tempRight(right.rbegin(),right.rend());
    //找到左侧最大的值
    for (int i = 0; i < len;++i)
    {
        if(i == 0)
        {
            max = input[i];

        }
        else
        {
            if(input[i] > max)
            {
                max = input[i];
            }

        }

        if(max <= input[i] && input[i] <= tempRight[i])
        {
            ret.push_back(input[i]);
        }
    }
    return ret;
}

int main()
{

    std::vector<int> v1{1, 2, 3, 4, 5, 6};
    std::vector<int> ret = Test(v1);
    for(auto iter:ret)
    {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
    return 0;
}
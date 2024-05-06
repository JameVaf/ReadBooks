#include<iostream>
#include<vector>

class Test
{
private:

public:
    std::vector<int> cal(const std::vector<int> &input)
    {
        std::vector<int> left, right, temp;
        size_t len = input.size();
        //循环找到所有对应左侧的值
        for (int i = 0; i < len;++i)
        {
            int ret = 1;
            for (int j = 0; j < i;++j)
            {
                ret *= input[j];
            }
            left.push_back(ret);
        }
        // 循环找到所有对应右侧的值
        for (int i = 0; i < len; ++i)
        {
            int ret = 1;
            for (int j = i+1; j < len; ++j)
            {
                ret *= input[j];
            }
            right.push_back(ret);
        }
        for (int i = 0; i < len;++i)
        {
            temp.push_back((left[i] * right[i]));
        }
        return temp;
    }
};

int main()
{
    Test v;
    std::vector<int> ret = v.cal(std::vector<int>{1, 2, 3, 4, 5});
    for(auto iter:ret)
    {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
    return 0;
}
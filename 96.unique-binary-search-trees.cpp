/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    static vector<int> total_arr;
    int numTrees(int n)
    {
        while (total_arr.size() <= n)
        {
            auto len = total_arr.size();
            total_arr.push_back(0);
            auto &new_value = total_arr.back();
            for (int i = 1; i <= len; ++i)
            {
                new_value += total_arr[i - 1] * total_arr[len - i];
            }
        }
        return total_arr[n];
        // auto res = 0;
        // vector<int> rightest_deep_number = {1};
        // while (--n)
        // {
        //     auto len = rightest_deep_number.size();
        //     vector<int> new_deep_number(len + 1, 0);
        //     for (int i = 0; i != len; ++i)
        //     {
        //         new_deep_number[0] += rightest_deep_number[i];
        //         new_deep_number[i + 1] += rightest_deep_number[i];

        //         for (int j = 1; j <= i; ++j)
        //         {
        //             new_deep_number[j] += rightest_deep_number[i];
        //         }
        //     }
        //     rightest_deep_number.swap(new_deep_number);
        // }
        // for (auto &deep : rightest_deep_number)
        // {
        //     res += deep;
        // }
        // return res;
    }
};
vector<int> Solution::total_arr = {1, 1};
// @lc code=end

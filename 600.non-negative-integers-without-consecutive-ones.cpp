/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findIntegers(int n)
    {
        vector<int> fib = {1, 2};
        for (int i = 2; i != 31; ++i)
        {
            fib.push_back(fib.back() + fib[fib.size() - 2]);
        }
        int res = 0;
        bool pre_one = false;
        for (int i = 30; i != -1; --i)
        {
            if (n & (1 << i))
            {
                res += fib[i];
                if (pre_one)
                {
                    return res;
                }
                else
                {
                    pre_one = true;
                }
            }
            else
            {
                pre_one = false;
            }
        }
        return res + 1;
    }
};
// @lc code=end

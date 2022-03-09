/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int candidates[9];
    constexpr int cont_one_num(int len)
    {
        int res = 0;
        while (len)
        {
            res *= 10;
            res += 1;
            --len;
        }
        return res;
    }

public:
    constexpr Solution() : candidates()
    {
        for (int i = 1; i != 10; ++i)
        {
            candidates[i - 1] = cont_one_num(10 - i);
        }
    }
    int monotoneIncreasingDigits(int n)
    {
        int res = 0;
        int max_add = 9;
        for (int i = 0; i != 9; ++i)
        {
            int val = min(n / candidates[i], max_add) * candidates[i];
            res += val;
            n -= val;
            max_add = 9 - res % 10;
        }
        return res;
    }
};
// @lc code=end

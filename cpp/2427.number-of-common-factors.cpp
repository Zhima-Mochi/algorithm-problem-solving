/*
 * @lc app=leetcode id=2427 lang=cpp
 *
 * [2427] Number of Common Factors
 */
#include <algorithm>
using namespace std;
// @lc code=start
// t: O(sqrt(n)) s: O(1)
class Solution
{
public:
    int commonFactors(int a, int b)
    {
        if (a > b)
        {
            swap(a, b);
        }
        while (a > 0)
        {
            b %= a;
            swap(a, b);
        }
        int res = 0;
        for (int i = 1; i * i <= b; ++i)
        {
            if (b % i == 0)
            {
                res += 2;
            }
            if (i * i == b)
            {
                res -= 1;
            }
        }
        return res;
    }
};
// @lc code=end

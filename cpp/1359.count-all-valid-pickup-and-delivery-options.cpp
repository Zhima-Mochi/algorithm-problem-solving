/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
// t:O(n), s:O(1)
class Solution
{
    int mod = 1000000007;

public:
    int countOrders(int n)
    {
        long long res = 1;
        for (int i = 1; i != n; ++i)
        {
            int num = (2 * i + 1) * i;
            num += 2 * i + 1;
            res *= num;
            res %= mod;
        }
        return res;
    }
};
// @lc code=end

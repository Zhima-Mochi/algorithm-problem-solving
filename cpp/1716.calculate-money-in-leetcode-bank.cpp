/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution
{
public:
    int totalMoney(int n)
    {
        if (n < 8)
        {
            return (1 + n) * n / 2;
        }
        else
        {
            n -= 7;
            return 28 + n + totalMoney(n);
        }
    }
};
// @lc code=end

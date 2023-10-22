/*
 * @lc app=leetcode id=2652 lang=cpp
 *
 * [2652] Sum Multiples
 */

// @lc code=start
// t:O(1), s:O(1)
class Solution
{
public:
    int sumOfMultiples(int n)
    {
        return sumMul(n, 3) + sumMul(n, 5) + sumMul(n, 7) - sumMul(n, 15) - sumMul(n, 21) - sumMul(n, 35) + sumMul(n, 105);
    }
    int sumMul(int n, int m)
    {
        if (n < m)
        {
            return 0;
        }
        return m * (1 + n / m) * (n / m) / 2;
    }
};
// @lc code=end

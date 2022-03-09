/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution
{
public:
    int divide(int &dividend, int &divisor)
    {
        long res = static_cast<long>(dividend) / divisor;
        if ((res >> 31) != 0 && (res >> 32) != ~0)
        {
            return res > 0 ? ~(1 << 31) : 1 << 31;
        }
        return res;
    }
};
// @lc code=end

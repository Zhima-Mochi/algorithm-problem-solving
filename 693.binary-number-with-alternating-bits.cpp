/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        n ^= (n >> 2);
        return !(n & n - 1);
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=2119 lang=cpp
 *
 * [2119] A Number After a Double Reversal
 */

// @lc code=start
class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        return num == 0 || num % 10 != 0;
    }
};
// @lc code=end

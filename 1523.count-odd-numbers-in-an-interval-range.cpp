/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution
{
public:
    int countOdds(int low, int high)
    {
        return low % 2 ? (high - low) / 2 + 1 : (high - low + 1) / 2;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=2600 lang=cpp
 *
 * [2600] K Items With the Maximum Sum
 */

// @lc code=start
// t:O(1), s:O(1)
class Solution
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        int res = 0;
        if (k <= numOnes)
        {
            return k;
        }
        k -= numOnes;
        res = numOnes;
        if (k <= numZeros)
        {
            return res;
        }
        k -= numZeros;
        return res - k;
    }
};
// @lc code=end

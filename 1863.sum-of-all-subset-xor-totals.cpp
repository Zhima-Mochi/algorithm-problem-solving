/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int res = 0;
        for (auto n : nums)
        {
            res |= n;
        }
        return res * (1 << nums.size() - 1);
    }
};
// @lc code=end

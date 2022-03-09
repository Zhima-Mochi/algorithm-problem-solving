/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
        {
            return nums[0];
        }
        return max(helpler(nums, 0, len - 1), helpler(nums, 1, len));
    }
    int helpler(vector<int> &nums, int start, int end)
    {
        int pre_val = nums[start], pre_pre_val = 0;
        for (int i = start + 1; i < end; ++i)
        {
            auto temp = max(pre_pre_val + nums[i], pre_val);
            pre_pre_val = pre_val;
            pre_val = temp;
        }
        return max(pre_pre_val, pre_val);
    }
};
// @lc code=end
/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int max_val = nums[0];
        int accum = nums[0];
        for (int i = 1, width = nums.size(); i != width; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                accum += nums[i];
            }
            else
            {
                max_val = max(max_val, accum);
                accum = nums[i];
            }
        }
        return max(max_val, accum);
    }
};
// @lc code=end

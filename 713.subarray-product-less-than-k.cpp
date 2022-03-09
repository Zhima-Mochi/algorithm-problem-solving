/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
        {
            return 0;
        }
        int res = 0;
        int width = nums.size();
        int left = 0;
        int cum_val = 1;
        for (int right = 0; right != width; ++right)
        {
            cum_val *= nums[right];
            while (cum_val >= k)
            {
                cum_val /= nums[left++];
            }
            res += right - left + 1;
        }
        return res;
    }
};
// @lc code=end

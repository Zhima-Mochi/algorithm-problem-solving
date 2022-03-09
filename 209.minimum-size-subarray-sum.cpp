/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (nums[0] >= target)
        {
            return 1;
        }
        nums.push_back(0);
        int len = nums.size();
        for (int i = len - 2; i != -1; --i)
        {
            nums[i] += nums[i + 1];
        }
        auto left = len - 2, right = len - 1;

        int res = len;
        while (left != -1)
        {
            if (nums[left] - nums[right] < target)
            {
                --left;
            }
            else
            {
                res = min(res, right - left);
                if (res == 1)
                {
                    return 1;
                }
                --right;
            }
        }
        return res == len ? 0 : res;
    }
};
// @lc code=end

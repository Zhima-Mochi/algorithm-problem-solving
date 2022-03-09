/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 4)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        if (static_cast<long>(target) < 4 * static_cast<long>(nums[0]) || static_cast<long>(target) > 4 * static_cast<long>(nums[len - 1]))
        {
            return res;
        }
        for (int i = 0; i != len - 3 && static_cast<long>(nums[i]) * 4 <= static_cast<long>(target); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            threeSum(res, nums, target - nums[i], i + 1, len - 1);
        }
        return res;
    }
    void threeSum(vector<vector<int>> &res, vector<int> &nums, int target, int left_ind, int right_ind)
    {
        if (right_ind - left_ind + 1 < 3)
        {
            return;
        }
        if (target < 3 * nums[left_ind] || target > 3 * nums[right_ind])
        {
            return;
        }
        for (int i = left_ind; i != right_ind - 1 && 3 * nums[i] <= target; ++i)
        {
            if (i > left_ind && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = right_ind;
            while (left < right)
            {
                auto sum_val = nums[i] + nums[left] + nums[right];
                if (sum_val < target)
                {
                    ++left;
                    while (left < right && nums[left - 1] == nums[left])
                    {
                        ++left;
                    }
                }
                else if (sum_val > target)
                {
                    --right;
                    while (left < right && nums[right + 1] == nums[right])
                    {
                        --right;
                    }
                }
                else
                {
                    res.push_back({nums[left_ind - 1], nums[i], nums[left], nums[right]});
                    --right, ++left;
                    while (left < right && nums[left - 1] == nums[left])
                    {
                        ++left;
                    }
                    while (left < right && nums[right + 1] == nums[right])
                    {
                        --right;
                    }
                }
            }
        }
    }
};
// @lc code=end

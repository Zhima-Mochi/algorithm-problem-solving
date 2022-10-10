/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int res = 10001;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (target > nums[len - 1] + nums[len - 2] + nums[len - 3])
        {
            return nums[len - 1] + nums[len - 2] + nums[len - 3];
        }
        for (int i = 0; i < len - 2; ++i)
        {
            int left = i + 1, right = len - 1;
            int sub_target = target - nums[i];
            if (sub_target > nums[right] + nums[right - 1])
            {
                if (abs(nums[right] + nums[right - 1] - sub_target) < abs(res))
                {
                    res = nums[right] + nums[right - 1] - sub_target;
                }
                continue;
            }
            if (sub_target < nums[left] + nums[left + 1])
            {
                if (abs(nums[left] + nums[left + 1] - sub_target) < abs(res))
                {
                    res = nums[left] + nums[left + 1] - sub_target;
                }
                return res + target;
            }
            while (left < right)
            {

                if (nums[left] + nums[right] < sub_target)
                {
                    if (abs(nums[left] + nums[right] - sub_target) < abs(res))
                    {
                        res = nums[left] + nums[right] - sub_target;
                    }
                    ++left;
                }
                else if (nums[left] + nums[right] > sub_target)
                {
                    if (abs(nums[left] + nums[right] - sub_target) < abs(res))
                    {
                        res = nums[left] + nums[right] - sub_target;
                    }
                    --right;
                }
                else
                {
                    return target;
                }
            }
        }
        return target + res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        return binary_find_minimum(nums, 0, nums.size() - 1);
    }
    int binary_find_minimum(vector<int> &nums, int left, int right)
    {
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else if (nums[mid] == nums[right])
            {
                return min(binary_find_minimum(nums, left, mid), binary_find_minimum(nums, mid + 1, right));
            }
        }
        return nums[left];
    }
};
// @lc code=end

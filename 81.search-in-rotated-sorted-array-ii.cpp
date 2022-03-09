/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    bool binary_search(vector<int> &nums, int &left, int &right, int &target)
    {
        while (left < right)
        {

            auto mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return nums[left] == target;
    }

public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        if (left == right)
        {
            return target == nums[left];
        }
        if (target < nums[left] && target > nums[right])
        {
            return false;
        }
        if (nums[left] < nums[right])
        {
            return binary_search(nums, left, right, target);
        }
        while (right - left > 1)
        {
            auto mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[mid] == nums[left] && nums[mid] == nums[right])
            {
                ++left;
                --right;
            }
            else if (nums[mid] <= nums[right])
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                    return binary_search(nums, left, right, target);
                }
                else
                {
                    right = mid;
                }
            }
            else
            {
                if (target > nums[mid] || target <= nums[right])
                {
                    left = mid;
                }
                else
                {
                    right = mid - 1;
                    return binary_search(nums, left, right, target);
                }
            }
        }
        return nums[left] == target || nums[right] == target;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        auto len = nums.size();
        if (len == 0)
        {
            return vector<int>(2, -1);
        }
        int left = 0, right = len - 1;
        int pivot = -1;
        int pivot_left = -1, pivot_right = -1;
        //variable pivot is not necessary
        if (nums[left] > target || nums[right] < target)
        {
            return vector<int>(2, -1);
        }
        if (nums[left] == target)
        {

            pivot_left = pivot = left;
        }

        if (nums[right] == target)
        {
            pivot_right = pivot = right;
        }

        if (pivot == -1)
        {
            while (right - left > 1)
            {
                auto middle = left + (right - left) / 2;
                if (nums[middle] > target)
                {
                    right = middle;
                }
                else if (nums[middle] < target)
                {
                    left = middle;
                }
                else
                {
                    pivot = middle;
                    break;
                }
            }
            if (pivot == -1)
            {
                return vector<int>(2, -1);
            }
        }
        if (pivot_left == -1)
        {
            pivot_left = pivot;
        }
        if (pivot_right == -1)
        {
            pivot_right = pivot;
        }

        while (pivot_left - left > 1)
        {
            auto middle = left + (pivot_left - left) / 2;
            if (nums[middle] < target)
            {
                left = middle;
            }
            else
            {
                pivot_left = middle;
            }
        }
        while (right - pivot_right > 1)
        {
            auto middle = pivot_right + (right - pivot_right) / 2;
            if (nums[middle] > target)
            {
                right = middle;
            }
            else
            {
                pivot_right = middle;
            }
        }
        return vector<int>{pivot_left, pivot_right};
    }
};
// @lc code=end

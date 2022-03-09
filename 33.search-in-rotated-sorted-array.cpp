/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int basic_binary_search(unsigned long long &left_index, unsigned long long &right_index, vector<int> &nums, int &target)
    {
        while (right_index - left_index > 1)
        {
            auto middle_index = (left_index + right_index) / 2;
            if (nums[middle_index] == target)
            {
                return middle_index;
            }
            if (nums[middle_index] < target)
            {
                left_index = middle_index;
            }
            else
            {
                right_index = middle_index;
            }
        }
        return -1;
    }
    bool out_ragne(int &left_value, int &right_value, int &target)
    {
        if (target < left_value && target > right_value)
        {
            return true;
        }
        return false;
    }

public:
    int search(vector<int> &nums, int target)
    {
        unsigned long long left_index = 0;
        unsigned long long right_index = nums.size() - 1;
        bool must_be_right_part = true;
        if (target == nums[left_index])
        {
            return left_index;
        }
        else if (target == nums[right_index])
        {
            return right_index;
        }

        if (out_ragne(nums[left_index], nums[right_index], target))
        {
            return -1;
        }
        else if (nums[left_index] < nums[right_index])
        {
            return basic_binary_search(left_index, right_index, nums, target);
        }
        else if (target > nums[left_index])
        {
            must_be_right_part = false;
        }

        while (right_index - left_index > 1)
        {
            auto middle_index = (left_index + right_index) / 2;
            if (nums[middle_index] == target)
            {
                return middle_index;
            }
            bool middle_is_right_part = nums[middle_index] < nums[right_index];

            if (middle_is_right_part && must_be_right_part && target > nums[middle_index])
            {
                left_index = middle_index;
                return basic_binary_search(left_index, right_index, nums, target);
            }
            else if (!middle_is_right_part && !must_be_right_part && target < nums[middle_index])
            {
                right_index = middle_index;
                return basic_binary_search(left_index, right_index, nums, target);
            }
            if (middle_is_right_part)
            {
                right_index = middle_index;
            }
            else
            {
                left_index = middle_index;
            }
        }

        return -1;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long max_val = static_cast<long>(1 << 31) - 1;
        for (auto &n : nums)
        {
            max_val = max(max_val, static_cast<long>(n));
        }
        long second_max = static_cast<long>(1 << 31) - 1;
        for (auto &n : nums)
        {
            if (n < max_val)
            {
                second_max = max(second_max, static_cast<long>(n));
            }
        }
        if (second_max == static_cast<long>(1 << 31) - 1)
        {
            return max_val;
        }

        long third_max = static_cast<long>(1 << 31) - 1;
        for (auto &n : nums)
        {
            if (n < second_max)
            {
                third_max = max(third_max, static_cast<long>(n));
            }
        }
        if (third_max == static_cast<long>(1 << 31) - 1)
        {
            return max_val;
        }
        else
        {
            return third_max;
        }
    }
    // void quick_sort(vector<int> &nums, int &res, int left, int right, int target)
    // {
    //     if (target == 1)
    //     {
    //         res = nums[left];
    //         for (int i = left; i <= right; ++i)
    //         {
    //             res = max(res, nums[i]);
    //         }
    //         return;
    //     }
    //     srand(time(nullptr));
    //     int random_variable = rand() % (right - left) + left;
    //     auto start = left, end = right;
    //     while (left < random_variable)
    //     {
    //         if (nums[left] > nums[random_variable])
    //         {
    //             ++left;
    //         }
    //         else
    //         {
    //             --random_variable;
    //             swap(nums[random_variable], nums[random_variable + 1]);
    //             swap(nums[left], nums[right]);
    //             --right;
    //         }
    //     }
    //     while (right > random_variable)
    //     {
    //         if (nums[right] <= nums[random_variable])
    //         {
    //             --right;
    //         }
    //         else
    //         {
    //             ++random_variable;
    //             swap(nums[random_variable], nums[random_variable - 1]);
    //             swap(nums[random_variable - 1], nums[right]);
    //             ++left;
    //         }
    //     }
    //     if (random_variable - start + 1 == target)
    //     {
    //         res = random_variable;
    //     }
    //     else if (random_variable - start + 1 > target)
    //     {
    //         quick_sort(nums, res, start, random_variable - 1, target);
    //     }
    //     else
    //     {
    //         quick_sort(nums, res, random_variable + 1, end, target - (random_variable - start) - 1);
    //     }
    // }
};
// @lc code=end

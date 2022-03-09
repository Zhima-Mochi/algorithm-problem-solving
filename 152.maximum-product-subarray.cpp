/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int len = nums.size();
        int res = nums[0];
        for (int i = 1, max_mul = nums[0], min_mul = nums[0]; i != len; ++i)
        {
            if (nums[i] < 0)
            {
                swap(max_mul, min_mul);
            }
            max_mul = max(nums[i], max_mul * nums[i]);
            min_mul = min(nums[i], min_mul * nums[i]);
            res = max(max_mul, res);
        }
        return res;
        // int res = nums[0];
        // size_t pos = 0;
        // auto len = nums.size();
        // while (pos != len)
        // {
        //     findMax(nums, len, res, pos);
        //     if (pos != len)
        //     {
        //         res = max(res, 0);
        //     }
        // }
        // return res;
    }
    // void findMax(vector<int> &nums, size_t &len, int &res, size_t &pos)
    // {
    //     auto start_pos = pos;
    //     if (start_pos != len && nums[start_pos] == 0)
    //     {
    //         ++start_pos;
    //     }
    //     if (start_pos == len)
    //     {
    //         pos = len;
    //         return;
    //     }
    //     auto end_pos = start_pos;
    //     int negative_count = 0;
    //     for (; end_pos != len && nums[end_pos] != 0; ++end_pos)
    //     {
    //         if (nums[end_pos] < 0)
    //         {
    //             ++negative_count;
    //         }
    //     }
    //     pos = end_pos;
    //     if (negative_count % 2 == 0)
    //     {
    //         int val = nums[start_pos];
    //         for (int i = start_pos + 1; i < end_pos; ++i)
    //         {
    //             val *= nums[i];
    //         }
    //         res = max(res, val);
    //         return;
    //     }
    //     else
    //     {
    //         int left_cur = start_pos, right_cur = end_pos - 1;

    //         auto left_sum = nums[left_cur] > 0 ? 1 : 0;
    //         auto right_sum = nums[right_cur] > 0 ? 1 : 0;
    //         while (nums[left_cur] > 0)
    //         {
    //             left_sum *= nums[left_cur];
    //             ++left_cur;
    //         }
    //         while (nums[right_cur] > 0)
    //         {
    //             right_sum *= nums[right_cur];
    //             --right_cur;
    //         }
    //         auto middle_sum = 1;
    //         for (int i = left_cur + 1; i <= right_cur - 1; ++i)
    //         {
    //             middle_sum *= nums[i];
    //         }
    //         if (left_sum != 0)
    //         {
    //             res = max(res, middle_sum * left_sum * nums[left_cur]);
    //             res = max(res, left_sum);
    //         }
    //         else
    //         {
    //             res = max(res, middle_sum * nums[left_cur]);
    //         }
    //         if (right_sum != 0)
    //         {
    //             res = max(res, middle_sum * right_sum * nums[right_cur]);
    //             res = max(res, right_sum);
    //         }
    //         else
    //         {
    //             res = max(res, middle_sum * nums[right_cur]);
    //         }
    //     }
    // }
};
// @lc code=end
//[2,-5,-2,-4,3]

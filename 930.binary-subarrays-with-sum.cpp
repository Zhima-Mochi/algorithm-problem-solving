/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int res = 0;
        int left1 = 0, left2 = 0, right = 0;
        int sum1 = 0, sum2 = 0;
        int w = nums.size();
        while (right < w)
        {
            sum1 += nums[right];
            while (left1 <= right && sum1 > goal)
            {
                sum1 -= nums[left1];
                ++left1;
            }
            sum2 += nums[right];
            while (left2 <= right && sum2 >= goal)
            {
                sum2 -= nums[left2];
                ++left2;
            }
            res += left2 - left1;
            ++right;
        }
        return res;
    }
};
// @lc code=end

// t:O(N), s:O(1)
// class Solution
// {
// public:
//     int numSubarraysWithSum(vector<int> &nums, int goal)
//     {
//         int res = 0;
//         if (goal > 0)
//         {
//             int pre_zero = 0;
//             int left = 0;
//             while (nums[left] == 0)
//             {
//                 ++left;
//                 ++pre_zero;
//             }
//             int right = left;
//             int w = nums.size();
//             int cnt = 0;
//             while (cnt < goal && right != w)
//             {
//                 if (nums[right++] == 1)
//                 {
//                     ++cnt;
//                 }
//             }
//             if (cnt == goal)
//             {
//                 res += pre_zero + 1;
//             }
//             while (right != w)
//             {
//                 if (nums[right] == 0)
//                 {
//                     res += (pre_zero + 1);
//                 }
//                 else
//                 {
//                     pre_zero = 0;
//                     while (nums[++left] == 0)
//                     {
//                         ++pre_zero;
//                     }
//                     res += pre_zero + 1;
//                 }
//                 ++right;
//             }
//             return res;
//         }
//         int zero_cnt = 0;
//         for (auto n : nums)
//         {
//             if (n == 0)
//             {
//                 ++zero_cnt;
//                 res += zero_cnt;
//             }
//             else
//             {
//                 zero_cnt = 0;
//             }
//         }
//         return res;
//     }
// };
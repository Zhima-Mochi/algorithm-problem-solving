/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N), s:O(N)
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long res = 0;
        int w = nums.size();
        vector<int> minLeft(w), minRight(w), maxLeft(w), maxRight(w);
        vector<int> stk_min, stk_max;
        for (int i = 0; i != w; ++i)
        {
            while (!stk_min.empty() && nums[stk_min.back()] > nums[i])
            {
                stk_min.pop_back();
            }
            minLeft[i] = stk_min.empty() ? -1 : stk_min.back();
            stk_min.push_back(i);
            while (!stk_max.empty() && nums[stk_max.back()] <= nums[i])
            {
                stk_max.pop_back();
            }
            maxLeft[i] = stk_max.empty() ? -1 : stk_max.back();
            stk_max.push_back(i);
        }
        stk_max.clear();
        stk_min.clear();
        for (int i = w - 1; i != -1; --i)
        {
            while (!stk_min.empty() && nums[stk_min.back()] >= nums[i])
            {
                stk_min.pop_back();
            }
            minRight[i] = stk_min.empty() ? w : stk_min.back();
            stk_min.push_back(i);
            while (!stk_max.empty() && nums[stk_max.back()] < nums[i])
            {
                stk_max.pop_back();
            }
            maxRight[i] = stk_max.empty() ? w : stk_max.back();
            stk_max.push_back(i);
        }
        for (int i = 0; i != w; ++i)
        {
            res += static_cast<long long>(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
            res -= static_cast<long long>(minRight[i] - i) * (i - minLeft[i]) * nums[i];
        }
        return res;
    }
};
// @lc code=end

// t:O(N^2), s:O(1)
// class Solution
// {
// public:
//     long long subArrayRanges(vector<int> &nums)
//     {
//         long long res = 0;
//         int max_val, min_val;
//         int w = nums.size();
//         for (int i = 0; i != w; ++i)
//         {
//             max_val = min_val = nums[i];
//             for (int j = i - 1; j != -1; --j)
//             {
//                 max_val = max(max_val, nums[j]);
//                 min_val = min(min_val, nums[j]);
//                 res += static_cast<long long>(max_val) - min_val;
//             }
//         }
//         return res;
//     }
// };
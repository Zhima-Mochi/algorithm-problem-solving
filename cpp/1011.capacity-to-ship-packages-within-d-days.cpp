/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start

// t:O(log(sum(weights))*len(weights)), s:O(1)
class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int w = weights.size();
        int total = accumulate(weights.begin(), weights.end(), 0);
        int left = max(total / days + (total % days ? 1 : 0), *max_element(weights.begin(), weights.end()));
        int right = total;
        while (left < right)
        {
            int day_cnt = 1;
            int mid = left + (right - left) / 2;
            int current_sum = 0;
            for (auto weight : weights)
            {
                if (current_sum + weight > mid)
                {
                    ++day_cnt;
                    current_sum = weight;
                }
                else
                {
                    current_sum += weight;
                }
                if (day_cnt > days)
                {
                    break;
                }
            }
            if (day_cnt > days)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

// // t:O(log(sum(weights))*logs(len(weights))), s:O(len(weights))
// class Solution
// {
// public:
//     int shipWithinDays(vector<int> &weights, int days)
//     {
//         int w = weights.size();
//         vector<int> dp = {0};
//         dp.reserve(w + 1);
//         for (int i = 0; i != w; ++i)
//         {
//             dp.push_back(dp[i] + weights[i]);
//         }
//         int left = dp.back() / days + (dp.back() % days ? 1 : 0);
//         int right = dp.back();
//         while (left < right)
//         {
//             int day_cnt = 0;
//             int mid = left + (right - left) / 2;
//             int idx = 1;
//             while (idx != w + 1)
//             {
//                 ++day_cnt;
//                 if (day_cnt > days)
//                 {
//                     break;
//                 }
//                 idx = upper_bound(dp.begin() + idx, dp.end(), dp[idx - 1] + mid) - dp.begin();
//             }
//             if (day_cnt > days)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid;
//             }
//         }
//         return left;
//     }
// };
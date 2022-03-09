/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
// t: O(N^2*K) s: O(N)
class Solution
{
public:
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int width = nums.size();
        double *dp = new double[width + 1];
        double *accum_num = new double[width + 1];
        for (auto i = 1; i != width + 1; ++i)
        {
            accum_num[i] = accum_num[i - 1] + nums[i - 1];
        }
        if (k >= width)
        {
            return accum_num[width];
        }
        for (int i = 1; i != width + 1; ++i)
        {
            dp[i] = accum_num[i] / i;
        }
        for (int i = 1; i != k; ++i)
        {
            for (int m = width; m != -1; --m)
            {
                for (int n = 0; n != m; ++n)
                {
                    dp[m] = max(dp[m], dp[n] + (accum_num[m] - accum_num[n]) / (m - n));
                }
            }
        }
        return dp[width];
    }
};
// @lc code=end

// t: O(N^2*K) s: O(N^2*K)
// class Solution
// {
//     double dp[101][101][101] = {};

// public:
//     double largestSumOfAverages(vector<int> &nums, int k)
//     {
//         int width = nums.size();
//         int sum_val = accumulate(nums.begin(), nums.end(), 0);
//         if (k >= width)
//         {
//             return sum_val;
//         }
//         return helpler(nums, 0, width - 1, k);
//     }
//     double helpler(vector<int> &nums, int start, int end, int part)
//     {
//         if (dp[start][end][part] != 0)
//         {
//             return dp[start][end][part];
//         }
//         if (part >= end - start + 1)
//         {
//             return dp[start][end][part] = accumulate(nums.begin() + start, nums.begin() + end + 1, 0.0);
//         }
//         else if (part == 1)
//         {
//             return dp[start][end][part] = accumulate(nums.begin() + start, nums.begin() + end + 1, 0.0) / (end - start + 1);
//         }
//         else
//         {
//             double max_val = accumulate(nums.begin() + start, nums.begin() + end + 1, 0.0) / (end - start + 1);
//             double sum_to_cur = 0;
//             for (auto cur = start; cur != end; ++cur)
//             {
//                 sum_to_cur += nums[cur];
//                 double val = sum_to_cur / (cur - start + 1) + helpler(nums, cur + 1, end, part - 1);
//                 max_val = max(max_val, val);
//             }
//             return dp[start][end][part] = max_val;
//         }
//     }
// };
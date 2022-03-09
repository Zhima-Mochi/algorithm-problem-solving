/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include <vector>
#include <bitset>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        if (sum_val % 2)
        {
            return false;
        }
        else
        {
            sum_val /= 2;
        }
        bitset<10000> dp;
        for (auto n : nums)
        {
            dp |= dp << n;
            dp.set(n - 1);
            if (dp[sum_val - 1])
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     bool canPartition(vector<int> &nums)
//     {
//         int sum_val = accumulate(nums.begin(), nums.end(), 0);
//         if (sum_val % 2)
//         {
//             return false;
//         }
//         else
//         {
//             sum_val /= 2;
//         }
//         vector<bool> dp(sum_val + 1);
//         dp[0] = true;
//         for (auto n : nums)
//         {
//             auto next_dp = dp;
//             for (int i = 0; i + n < sum_val + 1; ++i)
//             {
//                 if (dp[i])
//                 {
//                     next_dp[i + n] = true;
//                 }
//             }
//             if (next_dp[sum_val])
//             {
//                 return true;
//             }
//             dp = move(next_dp);
//         }
//         return false;
//     }
// };
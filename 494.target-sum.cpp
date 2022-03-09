/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
    int len;

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        len = nums.size();
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        if (sum_val < target || (sum_val - target) % 2)
        {
            return 0;
        }
        int diff = (sum_val - target) / 2;
        vector<vector<int>> dp(len + 1, vector<int>(diff + 1));
        dp[0][0] = 1;
        for (int i = 1; i != len + 1; ++i)
        {
            for (int j = 0; j != diff + 1; ++j)
            {
                if (j + nums[i - 1] <= diff)
                {
                    dp[i][j + nums[i - 1]] += dp[i - 1][j];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[len][diff];
    }
};
// @lc code=end
// class Solution
// {
//     int len;

// public:
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         len = nums.size();
//         vector<unordered_map<int, int>> sum_count(len + 1);
//         sum_count[len][0] = 1;
//         helpler(nums, sum_count, 0, target);
//         return sum_count[0][target];
//     }
//     void helpler(vector<int> &nums, vector<unordered_map<int, int>> &sum_count, int &&depth, int target)
//     {
//         if (depth == len)
//         {
//             return;
//         }
//         if (sum_count[depth].count(target))
//         {
//             return;
//         }
//         helpler(nums, sum_count, depth + 1, target + nums[depth]);
//         helpler(nums, sum_count, depth + 1, target - nums[depth]);
//         sum_count[depth][target] += sum_count[depth + 1][target + nums[depth]];
//         sum_count[depth][target] += sum_count[depth + 1][target - nums[depth]];
//     }
// };
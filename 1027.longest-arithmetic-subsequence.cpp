/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N^2), s:O(N)
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int w = nums.size();
        vector<vector<int>> dp(w, vector<int>(1002, 1));
        int res = 1;
        for (int i = 1; i != w; ++i)
        {
            for (int j = 0; j != i; ++j)
            {
                dp[i][nums[i] - nums[j] + 500] = max(dp[i][nums[i] - nums[j] + 500], dp[j][nums[i] - nums[j] + 500] + 1);
                res = max(res, dp[i][nums[i] - nums[j] + 500]);
            }
        }
        return res;
    }
};
// @lc code=end

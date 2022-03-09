/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(N), s:O(N)
class Solution
{
public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
    {
        int w = nums.size();
        vector<vector<int>> first_accum(w, vector<int>(2)), second_accum(w, vector<int>(2));
        vector<vector<int>> left_dp(w, vector<int>(2)), right_dp(w, vector<int>(2));
        int first_sum_window = accumulate(nums.begin(), nums.begin() + firstLen, 0);
        int second_sum_window = accumulate(nums.begin(), nums.begin() + secondLen, 0);
        for (int i = firstLen; i != w + 1; ++i)
        {
            first_accum[i - 1][0] = first_sum_window;
            first_accum[i - firstLen][1] = first_sum_window;
            if (i != w)
            {
                first_sum_window += nums[i];
                first_sum_window -= nums[i - firstLen];
            }
        }
        for (int i = secondLen; i != w + 1; ++i)
        {
            second_accum[i - 1][0] = second_sum_window;
            second_accum[i - secondLen][1] = second_sum_window;
            if (i != w)
            {
                second_sum_window += nums[i];
                second_sum_window -= nums[i - secondLen];
            }
        }
        for (int i = 0; i != w; ++i)
        {
            if (i > 0)
            {
                left_dp[i][0] = max(left_dp[i - 1][0], first_accum[i][0]);
                left_dp[i][1] = max(left_dp[i - 1][1], second_accum[i][0]);

                right_dp[w - 1 - i][0] = max(right_dp[w - 1 - i + 1][0], first_accum[w - 1 - i][1]);
                right_dp[w - 1 - i][1] = max(right_dp[w - 1 - i + 1][1], second_accum[w - 1 - i][1]);
            }
            else
            {
                left_dp[i][0] = first_accum[i][0];
                left_dp[i][1] = second_accum[i][0];

                right_dp[w - 1 - i][0] = first_accum[w - 1 - i][1];
                right_dp[w - 1 - i][1] = second_accum[w - 1 - i][1];
            }
        }
        int res = 0;
        for (int i = 0; i < w - 1; ++i)
        {
            res = max({res, left_dp[i][0] + right_dp[i + 1][1], left_dp[i][1] + right_dp[i + 1][0]});
        }
        return res;
    }
};
// @lc code=end

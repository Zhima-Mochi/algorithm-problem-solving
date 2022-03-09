/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(MN), s:O(N)
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int w1 = nums1.size();
        int w2 = nums2.size();
        vector<int> dp(w2 + 1);
        for (int i = 0; i != w1; ++i)
        {
            int prev_val = dp[0];
            for (int j = 0; j != w2; ++j)
            {
                int next_prev_val = dp[j + 1];
                if (nums1[i] == nums2[j])
                {
                    dp[j + 1] = max({dp[j + 1], dp[j], prev_val + 1});
                }
                else
                {
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                }
                prev_val = next_prev_val;
            }
        }
        return dp[w2];
    }
};
// @lc code=end

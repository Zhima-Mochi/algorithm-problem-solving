/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int width1 = text1.size(), width2 = text2.size();
        vector<int> dp(width2 + 1);
        for (int i = 0; i != width1; ++i)
        {
            int prev_count = 0;
            for (int j = 0; j != width2; ++j)
            {
                int next_prev_count = dp[j + 1];
                if (text1[i] == text2[j])
                {
                    dp[j + 1] = prev_count + 1;
                }
                else
                {
                    dp[j + 1] = max(dp[j], dp[j + 1]);
                }
                prev_count = next_prev_count;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

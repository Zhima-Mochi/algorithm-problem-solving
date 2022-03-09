/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int width = s.size();
        int dp[width + 1];
        for (auto &n : dp)
        {
            n = 0;
        }
        int max_val = 0;
        for (int i = 0; i != width; ++i)
        {
            int prev_val = 0;
            for (int j = 0; i + 1 + j + 1 < width + 1; ++j)
            {
                int next_prev_val = dp[j + 1];
                if (s[i] == s[width - 1 - j])
                {
                    dp[j + 1] = prev_val + 2;
                }
                else
                {
                    dp[j + 1] = max(dp[j], dp[j + 1]);
                }
                prev_val = next_prev_val;
                max_val = max(max_val, dp[j + 1]);
            }
            max_val = max(max_val, prev_val + 1);
        }
        return max_val;
    }
};
// @lc code=end

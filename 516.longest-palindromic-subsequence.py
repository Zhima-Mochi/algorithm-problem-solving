#
# @lc app=leetcode id=516 lang=python3
#
# [516] Longest Palindromic Subsequence
#
# @lc code=start

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        width = len(s)
        dp = [0 for x in range(width+1)]
        max_val = 0
        for i in range(width):
            prev_val = 0
            for j in range(width-i-1):
                next_prev_val = dp[j+1]
                if s[i] == s[width-1-j]:
                    dp[j + 1] = prev_val + 2
                else:
                    dp[j + 1] = max(dp[j], dp[j + 1])
                prev_val = next_prev_val
                max_val = max(max_val, dp[j + 1])
            max_val = max(max_val, prev_val + 1)
        return max_val
# @lc code=end

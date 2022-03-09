#
# @lc app=leetcode id=1218 lang=python3
#
# [1218] Longest Arithmetic Subsequence of Given Difference
#
from collections import Counter
# @lc code=start


class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        prev_diff_max_count = Counter()
        res = 1
        for n in arr:
            prev_diff_max_count[n] = prev_diff_max_count[n-difference]+1
            res = max(res, prev_diff_max_count[n])
        return res
# @lc code=end

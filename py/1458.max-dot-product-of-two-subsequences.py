#
# @lc app=leetcode id=1458 lang=python3
#
# [1458] Max Dot Product of Two Subsequences
#
from typing import *
# @lc code=start
# t:O(m*n), s:O(m*n)

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        bound = ~(1 << 31)
        n1 = len(nums1)
        n2 = len(nums2)
        dp = [[bound]*(n2+1) for _ in range(n1+1)]
        for i in range(1, n1+1):
            for j in range(1, n2+1):
                dp[i][j] = max(nums1[i-1]*nums2[j-1], dp[i-1][j-1]+nums1[i-1]
                               * nums2[j-1], dp[i-1][j], dp[i][j-1])
        return dp[n1][n2]
# @lc code=end

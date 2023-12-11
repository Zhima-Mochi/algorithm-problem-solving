#
# @lc app=leetcode id=1478 lang=python3
#
# [1478] Allocate Mailboxes
#
from typing import *
# @lc code=start

# t:O(n*k+nlog(n)), s:O(n*k+n*n)


class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        n = len(houses)
        bound = (1 << 31)-1
        dp = [[bound]*(k+1) for _ in range(n+1)]
        dp[0][0] = 0
        houses.sort()

        @cache
        def helper(a, b):
            if a >= b:
                return 0
            ans = houses[b]-houses[a]
            return ans+helper(a+1, b-1)
        for i in range(1, n+1):
            for j in range(i):
                for m in range(k):
                    dp[i][m+1] = min(dp[i][m+1], dp[j][m]+helper(j, i-1))
        return dp[n][k]

# @lc code=end

#
# @lc app=leetcode id=1269 lang=python3
#
# [1269] Number of Ways to Stay in the Same Place After Some Steps
#

# @lc code=start
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        MOD = 10**9+7
        l = min(arrLen, steps+1)
        dp = [0]*l
        dp[0] = 1
        for _ in range(steps):
            prev = 0
            for j in range(l):
                if prev == 0 and dp[j] == 0:
                    break
                next_prev = dp[j]
                dp[j] += prev
                prev = next_prev
                if j < l-1:
                    dp[j] += dp[j+1]
                dp[j] %= MOD
        return dp[0]


# @lc code=end

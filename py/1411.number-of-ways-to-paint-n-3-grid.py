#
# @lc app=leetcode id=1411 lang=python3
#
# [1411] Number of Ways to Paint N × 3 Grid
#

# @lc code=start
# t:O(n), s:O(1)
class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 1000000007
        # 101: 6 -> 101: 3, 012: 2
        # 012: 6 -> 101: 2, 012: 2
        a = 6
        b = 6
        for _ in range(n-1):
            a, b = a*3+b*2, a*2+b*2
            a %= MOD
            b %= MOD
        return (a+b) % MOD


# @lc code=end

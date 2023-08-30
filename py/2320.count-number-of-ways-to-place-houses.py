#
# @lc app=leetcode id=2320 lang=python3
#
# [2320] Count Number of Ways to Place Houses
#

# @lc code=start
# t:O(n), s:O(1)
class Solution:
    def countHousePlacements(self, n: int) -> int:
        MOD = 1000000007
        has_h = 0
        has_no_h = 1
        for _ in range(n):
            has_h, has_no_h = has_no_h, has_h+has_no_h
            has_h %= MOD
            has_no_h %= MOD
        res = has_h+has_no_h
        res *= res
        res %= MOD
        return res
# @lc code=end

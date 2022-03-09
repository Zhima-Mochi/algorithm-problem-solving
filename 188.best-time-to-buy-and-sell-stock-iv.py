#
# @lc app=leetcode id=188 lang=python3
#
# [188] Best Time to Buy and Sell Stock IV
#

# @lc code=start
# t:O(kn), s:O(k)
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        prev_hold = [-1001]*(k+1)
        prev_unhold = [0]*(k+1)
        for price in prices:
            next_prev_hold = prev_hold
            for i in range(1, k+1):
                next_prev_hold[i-1] = max(next_prev_hold[i-1],
                                          prev_unhold[i]-price)
            next_prev_unhold = prev_unhold
            for i in range(k+1):
                next_prev_unhold[i] = max(
                    next_prev_unhold[i], prev_hold[i]+price)
            prev_hold = next_prev_hold
            prev_unhold = next_prev_unhold
        return max(prev_unhold)
# @lc code=end

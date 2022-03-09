#
# @lc app=leetcode id=714 lang=python3
#
# [714] Best Time to Buy and Sell Stock with Transaction Fee
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        profit = 0
        cost = 1000000
        for p in prices:
            if p > cost:
                profit += p-cost
                cost = p
            elif p+fee < cost:
                cost = p+fee
        return profit

# @lc code=end

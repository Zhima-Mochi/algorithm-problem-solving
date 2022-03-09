#
# @lc app=leetcode id=518 lang=python3
#
# [518] Coin Change 2
#

# @lc code=start
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0 for x in range(amount+1)]
        dp[0] = 1
        for coin in coins:
            for i in range(amount-coin+1):
                if dp[i]:
                    dp[i+coin] += dp[i]
        return dp[amount]
# @lc code=end

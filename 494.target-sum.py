#
# @lc app=leetcode id=494 lang=python3
#
# [494] Target Sum
#

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        length = len(nums)
        sum_val = sum(nums)
        if sum_val < target or (sum_val-target) % 2:
            return 0
        diff = (sum_val-target)//2
        dp = [[0 for x in range(diff+1)] for y in range(length+1)]
        dp[0][0] = 1
        for i in range(1, length+1):
            for j in range(diff+1):
                if j+nums[i-1] <= diff:
                    dp[i][j+nums[i-1]] += dp[i-1][j]
                dp[i][j] += dp[i-1][j]
        return dp[length][diff]
# @lc code=end

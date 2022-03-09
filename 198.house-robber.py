#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#
from typing import *
# @lc code=start


class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [nums[0], 0]
        for i in range(1, len(nums)):
            dp[0], dp[1] = dp[1]+nums[i], max(dp)
        return max(dp)

# @lc code=end

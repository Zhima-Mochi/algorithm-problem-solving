#
# @lc app=leetcode id=1413 lang=python3
#
# [1413] Minimum Value to Get Positive Step by Step Sum
#

# @lc code=start
import itertools


class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        return 1-min(itertools.accumulate(nums, initial=0))

# @lc code=end

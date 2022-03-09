#
# @lc app=leetcode id=977 lang=python3
#
# [977] Squares of a Sorted Array
#
from typing import *
# @lc code=start


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            nums[i] *= nums[i]
        nums.sort()
        return nums
# @lc code=end

#
# @lc app=leetcode id=283 lang=python3
#
# [283] Move Zeroes
#

from typing import *

# @lc code=start


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[left] = nums[left], nums[i]
                left+=1

# @lc code=end

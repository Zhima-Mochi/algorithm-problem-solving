#
# @lc app=leetcode id=189 lang=python3
#
# [189] Rotate Array
#
from typing import List
# @lc code=start


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        width = len(nums)
        k %= width
        nums.reverse()
        for i in range(k//2):
            nums[i], nums[k-1-i] = nums[k-1-i], nums[i]
        for i in range((width-k)//2):
            nums[k+i], nums[width-1-i] = nums[width-1-i], nums[k+i]
        # nums[:k] = nums[:k][::-1]
        # nums[k:] = nums[k:][::-1]

# @lc code=end

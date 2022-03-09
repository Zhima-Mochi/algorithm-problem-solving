#
# @lc app=leetcode id=1800 lang=python3
#
# [1800] Maximum Ascending Subarray Sum
#
# @lc code=start

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        max_val = nums[0]
        accum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                accum += nums[i]
            else:
                max_val = max(max_val, accum)
                accum = nums[i]
        return max(max_val, accum)
# @lc code=end

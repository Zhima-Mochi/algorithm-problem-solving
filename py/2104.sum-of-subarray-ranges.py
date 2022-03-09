#
# @lc app=leetcode id=2104 lang=python3
#
# [2104] Sum of Subarray Ranges
#

# @lc code=start
# t:O(N), s:O(1)
class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        res = 0
        for i in range(len(nums)):
            max_val = nums[i]
            min_val = nums[i]
            for j in range(i+1, len(nums)):
                max_val = max(max_val, nums[j])
                min_val = min(min_val, nums[j])
                res += max_val-min_val
        return res
# @lc code=end

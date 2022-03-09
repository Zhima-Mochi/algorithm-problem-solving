#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_val = nums[0]
        cur = 0
        for n in nums:
            if cur < 0:
                cur = n
            else:
                cur += n
            max_val = max(max_val, cur)
        return max_val
# @lc code=end

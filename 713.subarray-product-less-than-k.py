#
# @lc app=leetcode id=713 lang=python3
#
# [713] Subarray Product Less Than K
#

# @lc code=start
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        res = 0
        width = len(nums)
        left = 0
        cum_val = 1
        for right in range(width):
            cum_val *= nums[right]
            while cum_val >= k:
                cum_val //= nums[left]
                left += 1
            res += right-left+1
        return res
# @lc code=end

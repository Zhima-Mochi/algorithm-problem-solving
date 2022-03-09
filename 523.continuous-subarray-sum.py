#
# @lc app=leetcode id=523 lang=python3
#
# [523] Continuous Subarray Sum
#

# @lc code=start
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        seen = set()
        seen.add(nums[0] % k)
        shift = 0
        for i in range(1, len(nums)):
            shift += nums[i]
            shift % k
            if (-shift+k) % k in seen:
                return True
            seen.add((-shift+k+nums[i]) % k)
        return False

# @lc code=end

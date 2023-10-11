#
# @lc app=leetcode id=2009 lang=python3
#
# [2009] Minimum Number of Operations to Make Array Continuous
#
from typing import *
from collections import *
# @lc code=start

# t:O(nlog(n)), s:O(1)


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        nums.sort()
        res = (1 << 31)-1
        n = len(nums)
        left = 0
        right = 0
        repeat = 0
        while right < n:
            if right > 0 and nums[right-1] == nums[right]:
                repeat += 1
            while nums[left]+n-1 < nums[right]:
                left += 1
                if nums[left] == nums[left-1]:
                    repeat -= 1
            res = min(res, n-(right-left+1-repeat))
            right += 1
        return res

# @lc code=end

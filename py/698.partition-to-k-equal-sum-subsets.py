#
# @lc app=leetcode id=698 lang=python3
#
# [698] Partition to K Equal Sum Subsets
#

# @lc code=start
from typing import *


class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        sum_val = sum(nums)
        if sum_val % k:
            return False
        self.length = len(nums)
        self.k = k
        self.required_num = sum_val//k
        nums.sort(reverse=True)
        subset = [0]*k
        return self.backtrack(subset, nums, 0)

    def backtrack(self, subset: List[int], nums: List[int], pos: int) -> bool:
        if pos == self.length:
            return True
        for i in range(self.k):
            seen = False
            for j in range(i):
                if subset[i] == subset[j]:
                    seen = True
                    break
            if seen or subset[i] + nums[pos] > self.required_num:
                continue
            subset[i] += nums[pos]
            if self.backtrack(subset, nums, pos + 1):
                return True
            subset[i] -= nums[pos]
        return False
# @lc code=end

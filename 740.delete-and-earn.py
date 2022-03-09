#
# @lc app=leetcode id=740 lang=python3
#
# [740] Delete and Earn
#
from typing import *
# @lc code=start


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort(key=lambda x: -x)
        prev_del = nums[0]
        prev_non_del = 0
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                prev_del += nums[i]
            else:
                cur_non_del = max(prev_del, prev_non_del)
                if nums[i] == nums[i-1]-1:
                    prev_del = prev_non_del+nums[i]
                else:
                    prev_del = cur_non_del+nums[i]
                prev_non_del = cur_non_del
        return max(prev_del, prev_non_del)
# @lc code=end

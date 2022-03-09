#
# @lc app=leetcode id=1403 lang=python3
#
# [1403] Minimum Subsequence in Non-Increasing Order
#
from typing import *
# @lc code=start


class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        sum_val = sum(nums)
        count_sort = [0 for x in range(101)]
        for n in nums:
            count_sort[n] += 1
        count = 0
        res = []
        for i in range(100, 0, -1):
            while count_sort[i] and count <= sum_val/2:
                res.append(i)
                count += i
                count_sort[i] -= 1
            if count > sum_val/2:
                break
        return res
# @lc code=end

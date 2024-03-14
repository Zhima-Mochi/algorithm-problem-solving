#
# @lc app=leetcode id=2809 lang=python3
#
# [2809] Minimum Time to Make Array Sum At Most x
#
from typing import *
# @lc code=start


class Solution:
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        if sum(nums1) <= x:
            return 0
        n = len(nums1)
        idx = list(range(n))
        idx.sort(key=lambda x: nums2[x])
        nums1 = [nums1[idx[i]] for i in range(n)]
        nums2 = [nums2[idx[i]] for i in range(n)]
        left = 0
        right = 2*n
        while left < right:
            mid = left+(right-left)//2

# @lc code=end

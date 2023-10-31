#
# @lc app=leetcode id=1879 lang=python3
#
# [1879] Minimum XOR Sum of Two Arrays
#
from typing import *

# @lc code=start
# t:O(n*2^n) m:O(2^n)


class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        memo = {}
        memo[(1 << n)-1] = 0
        for i in range(n-1, -1, -1):
            temp = {}
            for mask in memo.keys():
                for j in range(n):
                    if mask & (1 << j) != 0:
                        temp[mask ^ (1 << j)] = min(
                            temp.get(mask ^ (1 << j), float('inf')), memo[mask] + (nums1[i] ^ nums2[j]))
            memo = temp
        return memo[0]
# @lc code=end

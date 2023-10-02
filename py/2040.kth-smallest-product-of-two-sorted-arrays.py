#
# @lc app=leetcode id=2040 lang=python3
#
# [2040] Kth Smallest Product of Two Sorted Arrays
#
from typing import List
from bisect import *
# @lc code=start

# t:O(log(M)*(n+m)), s:O(n+m)


class Solution:
    def countUsedPairs(self, mid, pos1, neg1, pos2, neg2):
        used = 0
        i = 0
        j = len(pos2) - 1
        while i < len(pos1):
            while j >= 0 and pos1[i] * pos2[j] > mid:
                j -= 1
            used += j + 1
            i += 1
        i = 0
        j = 0
        while i < len(neg1):
            while j < len(pos2) and neg1[i] * pos2[j] > mid:
                j += 1
            used += len(pos2) - j
            i += 1
        i = 0
        j = 0
        while i < len(pos1):
            while j < len(neg2) and pos1[i] * neg2[j] <= mid:
                j += 1
            used += j
            i += 1
        i = 0
        j = len(neg2) - 1
        while i < len(neg1):
            while j >= 0 and neg1[i] * neg2[j] <= mid:
                j -= 1
            used += len(neg2) - 1 - j
            i += 1
        return used

    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        pos1 = []
        neg1 = []
        pos2 = []
        neg2 = []
        for n in nums1:
            if n >= 0:
                pos1.append(n)
            else:
                neg1.append(n)
        for n in nums2:
            if n >= 0:
                pos2.append(n)
            else:
                neg2.append(n)
        left = min(nums1[0]*nums2[0], nums1[0]*nums2[-1],
                   nums1[-1]*nums2[0], nums1[-1]*nums2[-1])
        right = max(nums1[0]*nums2[0], nums1[0]*nums2[-1],
                    nums1[-1]*nums2[0], nums1[-1]*nums2[-1])
        while left < right:
            used = 0
            mid = (left+right)//2
            used = self.countUsedPairs(mid, pos1, neg1, pos2, neg2)
            if used < k:
                left = mid + 1
            else:
                right = mid
        return left


# @lc code=end

#
# @lc app=leetcode id=1944 lang=python3
#
# [1944] Number of Visible People in a Queue
#
from collections import *
from bisect import *
# @lc code=start
# t:O(n), s:O(n)


class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        right_h = []
        n = len(heights)
        ans = [0]*n
        for i in range(n-1, -1, -1):
            while right_h and right_h[-1] <= heights[i]:
                right_h.pop()
                ans[i] += 1
            if right_h:
                ans[i] += 1
            right_h.append(heights[i])
        return ans


# @lc code=end

#
# @lc app=leetcode id=1585 lang=python3
#
# [1585] Check If String Is Transformable With Substring Sort Operations
#
from collections import *
# @lc code=start


class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        n = len(s)
        pos = {i: deque() for i in range(10)}
        for i, digit in enumerate(s):
            pos[int(digit)].append(i)

        for i, digit in enumerate(t):
            d = int(digit)
            if not pos[d]:
                return False
            for j in range(d):
                if pos[j] and pos[j][0] < pos[d][0]:
                    return False
            pos[d].popleft()

        return True

# @lc code=end

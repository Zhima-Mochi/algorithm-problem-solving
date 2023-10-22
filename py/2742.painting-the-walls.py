#
# @lc app=leetcode id=2742 lang=python3
#
# [2742] Painting the Walls
#
from collections import *
from functools import *
from itertools import *
from typing import *
from math import *

# @lc code=start


class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        n = len(cost)
        f = [0] + [inf] * n
        for c, t in zip(cost, time):
            for j in range(n, 0, -1):
                f[j] = min(f[j], f[max(j - t - 1, 0)] + c)
        return f[n]

# @lc code=end

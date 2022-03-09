#
# @lc app=leetcode id=1996 lang=python3
#
# [1996] The Number of Weak Characters in the Game
#
from typing import *
# @lc code=start


class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda v: [-v[0], v[1]])
        current_max = 0
        res = 0
        for p in properties:
            if p[1] < current_max:
                res += 1
            else:
                current_max = p[1]
        return res
# @lc code=end

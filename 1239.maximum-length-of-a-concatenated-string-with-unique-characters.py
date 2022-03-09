#
# @lc app=leetcode id=1239 lang=python3
#
# [1239] Maximum Length of a Concatenated String with Unique Characters
#
from _typeshed import Self
from typing import *
# @lc code=start


class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def dfs(res: List[int], ls: Optional[List[int]], current: int, pos: int):
            res[0] = max(res[0], bin(current).count('1'))
            if pos == len(ls):
                return
            for i in range(pos, len(ls)):
                if current & ls[i] == 0:
                    dfs(res, ls, current | ls[i], i+1)
        ls = []
        for s in arr:
            val = 0
            for c in s:
                if (val & 1 << ord(c) - ord('a')) == 0:
                    val |= 1 << ord(c)-ord('a')
                else:
                    val = 0
                    break
            if val != 0:
                ls.append(val)
        res = [0]
        dfs(res, ls, 0, 0)
        return res[0]


# @lc code=end

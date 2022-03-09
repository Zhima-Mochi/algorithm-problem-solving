#
# @lc app=leetcode id=1399 lang=python3
#
# [1399] Count Largest Group
#
from typing import *
# @lc code=start


class Solution:
    def countLargestGroup(self, n: int) -> int:
        vec = [0 for x in range(37)]
        for i in range(1, n+1):
            vec[self.helpler(i)] += 1
        res = 0
        max_size = 0
        for v in vec:
            if v > max_size:
                res = 1
                max_size = v
            elif v == max_size:
                res += 1
        return res

    def helpler(self, num: int) -> int:
        res = 0
        while num:
            res += num % 10
            num //= 10
        return res
# @lc code=end

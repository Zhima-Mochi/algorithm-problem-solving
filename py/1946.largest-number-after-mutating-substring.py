#
# @lc app=leetcode id=1946 lang=python3
#
# [1946] Largest Number After Mutating Substring
#
from typing import *
# @lc code=start
# t:O(n), s:O(n)

class Solution:
    def maximumNumber(self, num: str, change: List[int]) -> str:
        num_ls = [int(n) for n in num]
        n = len(num_ls)
        isStart = False
        for i in range(n):
            if num_ls[i] > change[num_ls[i]]:
                if isStart:
                    break
            elif num_ls[i] < change[num_ls[i]]:
                num_ls[i] = change[num_ls[i]]
                isStart = True
        return ''.join(str(c) for c in num_ls)
# @lc code=end

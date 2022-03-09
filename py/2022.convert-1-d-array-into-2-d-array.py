#
# @lc app=leetcode id=2022 lang=python3
#
# [2022] Convert 1D Array Into 2D Array
#

# @lc code=start
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m*n != len(original):
            return []
        res = [None]*m
        c = 0
        r = 0
        elem = []
        for num in original:
            elem.append(num)
            c += 1
            if c == n:
                res[r] = elem
                r += 1
                elem = []
                c = 0
        return res

# @lc code=end

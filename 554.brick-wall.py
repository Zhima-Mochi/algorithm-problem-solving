#
# @lc app=leetcode id=554 lang=python3
#
# [554] Brick Wall
#

# @lc code=start
from collections import defaultdict


class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        border_count = defaultdict(int)
        for row_elem in wall:
            sum_val = 0
            for elem in row_elem:
                sum_val += elem
                border_count[sum_val] += 1
        height = len(wall)
        width = sum(wall[0])
        res = height
        border_count.pop(width)
        for val in border_count.values():
            res = min(res, height-val)
        return res
# @lc code=end

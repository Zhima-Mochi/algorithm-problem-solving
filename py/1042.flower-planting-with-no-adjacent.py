#
# @lc app=leetcode id=1042 lang=python3
#
# [1042] Flower Planting With No Adjacent
#

# @lc code=start
from collections import defaultdict
from typing import DefaultDict, List


class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        route_map: DefaultDict[int, List] = defaultdict(list)
        for path in paths:
            route_map[path[0]].append(path[1])
            route_map[path[1]].append(path[0])
        color_record = []
        for i in range(1, n+1):
            bit = 0
            for garden in route_map[i]:
                if garden < i:
                    bit |= 1 << color_record[garden-1]-1
            for j in range(1, 5):
                if (bit & 1) == 0:
                    color_record.append(j)
                    break
                bit >>= 1
        return color_record
# @lc code=end

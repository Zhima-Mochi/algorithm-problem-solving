#
# @lc app=leetcode id=2017 lang=python3
#
# [2017] Grid Game
#

# @lc code=start
# t:O(n), s:O(1)
class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        w = len(grid[0])
        first_sum = sum(grid[0][1:])
        second_sum = 0
        res = first_sum
        for i in range(w-1):
            first_sum -= grid[0][i+1]
            second_sum += grid[1][i]
            res = min(res, max(first_sum, second_sum))
        return res


# @lc code=end

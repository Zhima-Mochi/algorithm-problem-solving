#
# @lc app=leetcode id=1091 lang=python3
#
# [1091] Shortest Path in Binary Matrix
#
from collections import deque
# @lc code=start


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1
        if n == 1:
            return 1
        positions = deque([[0, 0]])
        res = 1
        grid[0][0] = 1
        while len(positions):
            res += 1
            q_len = len(positions)
            while q_len:
                q_len -= 1
                position = positions.popleft()
                for i in range(-1, 2):
                    for j in range(-1, 2):
                        row = position[0]+i
                        col = position[1]+j
                        if row >= 0 and col >= 0 and row < n and col < n and grid[row][col] == 0:
                            grid[row][col] = 1
                            if row == col == n-1:
                                return res
                            positions.append([row, col])
        return -1
# @lc code=end

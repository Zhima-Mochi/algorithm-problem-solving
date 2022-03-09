#
# @lc app=leetcode id=994 lang=python3
#
# [994] Rotting Oranges
#
from typing import *
from collections import deque
# @lc code=start


class Solution:
    def orangesRotting(self, grid: List[List]) -> int:
        direction = ((1, 0), (0, 1), (-1, 0), (0, -1))
        height = len(grid)
        width = len(grid[0])
        rotten_pos = deque()
        fresh_num = 0
        for i in range(height):
            for j in range(width):
                if grid[i][j] == 1:
                    fresh_num += 1
                elif grid[i][j] == 2:
                    rotten_pos.append((i, j))
        time_count = 0
        while fresh_num and len(rotten_pos):
            time_count += 1
            q_len = len(rotten_pos)
            while(q_len):
                q_len -= 1
                row = rotten_pos[0][0]
                col = rotten_pos[0][1]
                rotten_pos.popleft()
                for d in direction:
                    next_row = row + d[0]
                    next_col = col + d[1]
                    if next_row >= 0 and next_row <= height - 1 and next_col >= 0 and next_col <= width - 1:
                        if (grid[next_row][next_col] == 1):
                            fresh_num -= 1
                            grid[next_row][next_col] = 2
                            rotten_pos.append((next_row, next_col))
        if fresh_num:
            return -1
        else:
            return time_count

# @lc code=end

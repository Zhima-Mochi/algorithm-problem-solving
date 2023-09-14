#
# @lc app=leetcode id=2596 lang=python3
#
# [2596] Check Knight Tour Configuration
#

# @lc code=start
# t:O(mn), s:O(1)
class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        w = len(grid)
        pos = [0, 0]
        if grid[0][0] != 0:
            return False
        directions = [[1, 2], [-1, 2], [1, -2],
                      [-1, -2], [2, 1], [2, -1], [-2, 1], [-2, -1]]
        for i in range(1, w*w):
            flag = False
            for dir in directions:
                next_pos = [pos[0]+dir[0], pos[1]+dir[1]]
                if next_pos[0] >= 0 and next_pos[1] >= 0 and next_pos[0] < w and next_pos[1] < w and grid[next_pos[0]][next_pos[1]] == i:
                    pos = next_pos
                    flag = True
                    break
            if not flag:
                return False

        return True


# @lc code=end

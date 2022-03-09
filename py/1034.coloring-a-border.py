#
# @lc app=leetcode id=1034 lang=python3
#
# [1034] Coloring A Border
#

# @lc code=start
class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        new_color = color
        og_color = grid[row][col]
        height = len(grid)
        width = len(grid[0])

        def helpler(row, col):
            if grid[row][col] == -new_color or grid[row][col] == -og_color:
                return True
            elif grid[row][col] != og_color:
                return False
            grid[row][col] = -new_color
            is_inner = True
            for r in range(-1, 2, 2):
                if row+r >= 0 and row+r < height:
                    if not helpler(row+r, col):
                        is_inner = False
                else:
                    is_inner = False
            for c in range(-1, 2, 2):
                if col+c >= 0 and col+c < width:
                    if not helpler(row, col+c):
                        is_inner = False
                else:
                    is_inner = False
            if is_inner:
                grid[row][col] = -og_color
            return True
        helpler(row, col)
        for i in range(height):
            for j in range(width):
                if grid[i][j] < 0:
                    grid[i][j] *= -1
        return grid

# @lc code=end

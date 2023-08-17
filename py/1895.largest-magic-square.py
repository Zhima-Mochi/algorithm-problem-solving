#
# @lc app=leetcode id=1895 lang=python3
#
# [1895] Largest Magic Square
#

# @lc code=start
class Solution:
    h, w = 0, 0
    rowsum = []
    colsum = []

    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        self.h = len(grid)
        self.w = len(grid[0])

        self.rowsum = [[0] * self.w for _ in range(self.h)]
        for i in range(self.h):
            self.rowsum[i][0] = grid[i][0]
            for j in range(1, self.w):
                self.rowsum[i][j] = self.rowsum[i][j - 1] + grid[i][j]

        self.colsum = [[0] * self.w for _ in range(self.h)]
        for j in range(self.w):
            self.colsum[0][j] = grid[0][j]
            for i in range(1, self.h):
                self.colsum[i][j] = self.colsum[i - 1][j] + grid[i][j]

        res = 0
        for i in range(1, min(self.h, self.w)+1):
            if self.hasMagic(grid, i):
                res = i
        return res

    def hasMagic(self, grid, l):
        for i in range(self.h-l+1):
            for j in range(self.w-l+1):
                if self.isMagic(grid, i, j, l):
                    return True
        return False

    def isMagic(self, grid, r, c, l):
        goal = self.rowsum[r][c+l-1] - (self.rowsum[r][c-1] if c > 0 else 0)
        for i in range(r, r+l):
            if self.rowsum[i][c+l-1] - (self.rowsum[i][c-1] if c > 0 else 0) != goal:
                return False
        for j in range(c, c+l):
            if self.colsum[r+l-1][j] - (self.colsum[r-1][j] if r > 0 else 0) != goal:
                return False
        if sum(grid[r+i][c+i] for i in range(l)) != goal:
            return False
        if sum(grid[r+i][c+l-i-1] for i in range(l)) != goal:
            return False
        return True

# @lc code=end

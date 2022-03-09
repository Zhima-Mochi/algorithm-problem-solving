#
# @lc app=leetcode id=688 lang=python3
#
# [688] Knight Probability in Chessboard
#

# @lc code=start
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        directions = ((-1, -2), (-2, -1), (-2, 1), (-1, 2),
                      (1, 2), (2, 1), (2, -1), (1, -2))
        record = [[[None]*101 for _ in range(26)] for _ in range(26)]
        width = n
        
        def helpler(k, r, c):
            if k == 0:
                return 1
            if not record[r][c][k]:
                record[r][c][k] = 0
                for d in directions:
                    nr = r+d[0]
                    nc = c+d[1]
                    if nr >= 0 and nr < width and nc >= 0 and nc < width:
                        record[r][c][k] += helpler(k-1, nr, nc)/8
            return record[r][c][k]
        return helpler(k, row, column)
# @lc code=end

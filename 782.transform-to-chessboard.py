#
# @lc app=leetcode id=782 lang=python3
#
# [782] Transform to Chessboard
#

# @lc code=start
class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        width = len(board)
        if any(board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j] for i in range(width) for j in range(width)):
            return -1
        row_count = [0, 0]
        col_count = [0, 0]
        for i in range(width):
            if board[0][i]:
                row_count[i % 2] += 1
            if board[i][0]:
                col_count[i % 2] += 1
        res = 0

        if width % 2:
            if width//2+1 < row_count[0]+row_count[1] or row_count[0]+row_count[1] < width//2:
                return -1
            if width//2+1 < col_count[0]+col_count[1] or col_count[0]+col_count[1] < width//2:
                return -1
            if row_count[0] + row_count[1] == width // 2:
                res += row_count[0]
            else:
                res += row_count[1]
            if col_count[0] + col_count[1] == width // 2:
                res += col_count[0]
            else:
                res += col_count[1]
        else:
            if width//2 != row_count[0]+row_count[1] or width//2 != col_count[0]+col_count[1]:
                return -1
            res += min(row_count[0], row_count[1])
            res += min(col_count[0], col_count[1])
        return res

# @lc code=end

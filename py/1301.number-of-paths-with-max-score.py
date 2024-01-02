#
# @lc app=leetcode id=1301 lang=python3
#
# [1301] Number of Paths with Max Score
#

# @lc code=start
# t:O(n^2), s:O(n^2)
MOD = 1000000007


class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        m = len(board)
        n = len(board[0])
        board[0] = '0'+board[0][1:]
        dpVal = [[-1]*n for _ in range(m)]
        dpCnt = [[0]*n for _ in range(m)]
        dpVal[-1][-1] = 0
        dpCnt[-1][-1] = 1
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if dpVal[i][j] == -1:
                    continue
                val = dpVal[i][j]
                if i > 0:
                    if board[i-1][j] != 'X':
                        if val+int(board[i-1][j]) > dpVal[i-1][j]:
                            dpVal[i-1][j] = val+int(board[i-1][j])
                            dpCnt[i-1][j] = dpCnt[i][j]
                        elif val+int(board[i-1][j]) == dpVal[i-1][j]:
                            dpCnt[i-1][j] += dpCnt[i][j]
                            dpCnt[i-1][j] %= MOD
                if j > 0:
                    if board[i][j-1] != 'X':
                        if val+int(board[i][j-1]) > dpVal[i][j-1]:
                            dpVal[i][j-1] = val+int(board[i][j-1])
                            dpCnt[i][j-1] = dpCnt[i][j]
                        elif val+int(board[i][j-1]) == dpVal[i][j-1]:
                            dpCnt[i][j-1] += dpCnt[i][j]
                            dpCnt[i][j-1] %= MOD
                if i > 0 and j > 0:
                    if board[i-1][j-1] != 'X':
                        if val+int(board[i-1][j-1]) > dpVal[i-1][j-1]:
                            dpVal[i-1][j-1] = val+int(board[i-1][j-1])
                            dpCnt[i-1][j-1] = dpCnt[i][j]
                        elif val+int(board[i-1][j-1]) == dpVal[i-1][j-1]:
                            dpCnt[i-1][j-1] += dpCnt[i][j]
                            dpCnt[i-1][j-1] %= MOD
        if dpVal[0][0] == -1:
            return [0, 0]
        return [dpVal[0][0], dpCnt[0][0]]


# @lc code=end

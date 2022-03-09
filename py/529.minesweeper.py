#
# @lc app=leetcode id=529 lang=python3
#
# [529] Minesweeper
#
import collections
# @lc code=start


class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        height = len(board)
        width = len(board[0])
        q = collections.deque()
        q.append(click)
        while len(q):
            q_len = len(q)
            while q_len:
                pos = q.popleft()
                if board[pos[0]][pos[1]] == 'M':
                    board[pos[0]][pos[1]] = 'X'
                elif board[pos[0]][pos[1]] == 'E':
                    mines = 0
                    for i in range(-1, 2, 1):
                        for j in range(-1, 2, 1):
                            row = pos[0]+i
                            col = pos[1]+j
                            if row < 0 or row >= height or col < 0 or col >= width:
                                continue
                            if board[row][col] == 'M':
                                mines += 1
                    if mines > 0:
                        board[pos[0]][pos[1]] = chr(ord('0')+mines)
                    else:
                        board[pos[0]][pos[1]] = 'B'
                        for i in range(-1, 2, 1):
                            for j in range(-1, 2, 1):
                                row = pos[0]+i
                                col = pos[1]+j
                                if row < 0 or row >= height or col < 0 or col >= width:
                                    continue
                                if board[row][col] == 'E':
                                    q.append([row, col])
                q_len -= 1
        return board
# @lc code=end

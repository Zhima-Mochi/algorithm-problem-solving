#
# @lc app=leetcode id=542 lang=python3
#
# [542] 01 Matrix
#
from typing import *
# @lc code=start


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        height = len(mat)
        width = len(mat[0])
        for i in range(height):
            for j in range(width):
                if mat[i][j] == 0:
                    continue
                elif i == 0 and j == 0:
                    mat[i][j] = 100000000
                elif i == 0:
                    mat[i][j] = mat[i][j-1]+1
                elif j == 0:
                    mat[i][j] = mat[i-1][j]+1
                else:
                    mat[i][j] = min(mat[i][j-1], mat[i-1][j])+1
        for i in range(height-1, -1, -1):
            for j in range(width-1, -1, -1):
                if mat[i][j] == 0:
                    continue
                elif i == height-1 and j == width-1:
                    continue
                elif i == height-1:
                    mat[i][j] = min(mat[i][j], mat[i][j+1]+1)
                elif j == width-1:
                    mat[i][j] = min(mat[i][j], mat[i+1][j]+1)
                else:
                    mat[i][j] = min(mat[i][j], min(mat[i][j+1], mat[i+1][j])+1)
        return mat

# @lc code=end

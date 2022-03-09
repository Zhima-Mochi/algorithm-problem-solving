#
# @lc app=leetcode id=498 lang=python3
#
# [498] Diagonal Traverse
#

# @lc code=start
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        height = len(mat)
        width = len(mat[0])
        res = []
        row = 0
        col = 0
        upperward = True
        pos = 0
        while row < height and col < width:
            res.append(mat[row][col])
            if upperward:
                if row > 0 and col < width-1:
                    row -= 1
                    col += 1
                elif col == width-1:
                    upperward = False
                    row += 1
                elif row == 0:
                    upperward = False
                    col += 1
            else:
                if row < height-1 and col > 0:
                    row += 1
                    col -= 1
                elif row == height-1:
                    upperward = True
                    col += 1
                elif col == 0:
                    upperward = True
                    row += 1
        return res
# @lc code=end

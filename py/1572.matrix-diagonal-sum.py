#
# @lc app=leetcode id=1572 lang=python3
#
# [1572] Matrix Diagonal Sum
#

# @lc code=start
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        side_length = len(mat)
        res = 0
        for i in range(side_length):
            res += mat[i][i] + mat[i][side_length - 1 - i]

        if side_length % 2:
            res -= mat[side_length // 2][side_length // 2]
        return res
# @lc code=end

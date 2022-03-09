#
# @lc app=leetcode id=1380 lang=python3
#
# [1380] Lucky Numbers in a Matrix
#

# @lc code=start
class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        height = len(matrix)
        width = len(matrix[0])
        row_min = []
        res = []
        for row in matrix:
            row_min.append(min(row))
        for col in zip(*matrix):
            max_val = max(col)
            if max_val in row_min:
                res.append(max_val)
        return res
# @lc code=end

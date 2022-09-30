class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        h = len(matrix)
        w = len(matrix[0])
        row1_zero = False
        col1_zero = False
        for i in range(h):
            for j in range(w):
                if i == 0 and matrix[i][j] == 0:
                    row1_zero = True
                if j == 0 and matrix[i][j] == 0:
                    col1_zero = True
                if i > 0 and j > 0 and matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, h):
            for j in range(1, w):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if row1_zero:
            for j in range(w):
                matrix[0][j] = 0
        if col1_zero:
            for i in range(h):
                matrix[i][0] = 0

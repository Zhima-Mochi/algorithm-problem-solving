/*
 * @lc app=leetcode.cn id=304 lang=golang
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
package main

// @lc code=start
type NumMatrix struct {
	sumMatrix [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	h := len(matrix)
	w := len(matrix[0])
	sumMatrix := make([][]int, h+1)
	sumMatrix[0] = make([]int, w+1)
	for i := 1; i <= h; i++ {
		sumMatrix[i] = make([]int, w+1)
		rowSum := 0
		for j := 1; j <= w; j++ {
			rowSum += matrix[i-1][j-1]
			sumMatrix[i][j] = rowSum + sumMatrix[i-1][j]
		}
	}
	return NumMatrix{
		sumMatrix: sumMatrix,
	}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	ans := 0
	ans += this.sumMatrix[row2+1][col2+1] + this.sumMatrix[row1][col1]
	ans -= this.sumMatrix[row2+1][col1] + this.sumMatrix[row1][col2+1]
	return ans
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
// @lc code=end

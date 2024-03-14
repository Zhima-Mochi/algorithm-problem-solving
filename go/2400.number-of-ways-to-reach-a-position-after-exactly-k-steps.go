/*
 * @lc app=leetcode id=2400 lang=golang
 *
 * [2400] Number of Ways to Reach a Position After Exactly k Steps
 */
package main

// @lc code=start
const (
	MOD = 1000000007
)

var (
	memo = make(map[int]map[int]int, 1001)
)

func init() {
	memo[0] = make(map[int]int, 1001)
	memo[0][0] = 1
	for i := 1; i != 1001; i++ {
		memo[i] = make(map[int]int, 1001)
		for j := -i; j != i+1; j++ {
			memo[i][j-1] += memo[i-1][j]
			memo[i][j-1] %= MOD
			memo[i][j+1] += memo[i-1][j]
			memo[i][j+1] %= MOD
		}
	}
}

func numberOfWays(startPos int, endPos int, k int) int {
	pos := startPos - endPos
	return memo[k][pos]
}

// @lc code=end

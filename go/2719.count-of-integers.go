/*
 * @lc app=leetcode id=2719 lang=golang
 *
 * [2719] Count of Integers
 */
package main

// @lc code=start
const (
	MOD = 1000000007
	N   = 23
	M   = 401
)

func reverse(s string) string {
	runes := []rune(s)
	n := len(s)
	for i := 0; i != n/2; i++ {
		runes[i], runes[n-i-1] = runes[n-i-1], runes[i]
	}
	return string(runes)
}

func count(num1 string, num2 string, min_sum int, max_sum int) int {
	dp := make([][]int, N)
	for i := range dp {
		dp[i] = make([]int, M)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	var dfs func(num string, i, j int, limit bool) int

	dfs = func(num string, i, j int, limit bool) int {
		if j > max_sum {
			return 0
		}
		if i == -1 {
			if j >= min_sum {
				return 1
			}
			return 0
		}
		if !limit && dp[i][j] != -1 {
			return dp[i][j]
		}
		ans := 0
		bound := 0
		if limit {
			bound = int(num[i] - '0')
		} else {
			bound = 9
		}
		for x := 0; x <= bound; x++ {
			ans = (ans + dfs(num, i-1, j+x, limit && x == bound)) % MOD
		}

		if !limit {
			dp[i][j] = ans
		}
		return ans
	}

	add := func(num string) int {
		num = reverse(num)
		return dfs(num, len(num)-1, 0, true)
	}

	b := []byte(num1)
	n1 := len(b)
	n1--
	for b[n1] == '0' {
		n1--
	}
	b[n1]--
	n1++
	for n1 != len(b) {
		b[n1] = '9'
		n1++
	}
	num1 = string(b)
	return (add(num2) - add(num1) + MOD) % MOD
}

// @lc code=end

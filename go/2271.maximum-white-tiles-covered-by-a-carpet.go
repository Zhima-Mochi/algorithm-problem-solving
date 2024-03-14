/*
 * @lc app=leetcode id=2271 lang=golang
 *
 * [2271] Maximum White Tiles Covered by a Carpet
 */
package main

import "sort"

// @lc code=start
// t:O(nlog(n)), s:O(log(n))
func maximumWhiteTiles(tiles [][]int, carpetLen int) int {
	sort.Slice(tiles, func(i, j int) bool {
		return tiles[i][0] < tiles[j][0]
	})
	ans := 0
	left := 0
	right := 0
	n := len(tiles)
	l := 0
	for right != n {
		right++
		l += tiles[right-1][1] - tiles[right-1][0] + 1
		for left < right && tiles[right-1][1]-tiles[left][1] >= carpetLen {
			l -= tiles[left][1] - tiles[left][0] + 1
			left++
		}
		bound := tiles[right-1][1] - carpetLen + 1
		val := l
		if tiles[left][0] < bound {
			val -= bound - tiles[left][0]
		}
		if val > ans {
			ans = val
		}
	}
	return ans
}

// @lc code=end

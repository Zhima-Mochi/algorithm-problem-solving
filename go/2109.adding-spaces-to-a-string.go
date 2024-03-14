/*
 * @lc app=leetcode id=2109 lang=golang
 *
 * [2109] Adding Spaces to a String
 */
package main

import (
	"strings"
)

// @lc code=start
// t:O(n), s:O(n)
func addSpaces(s string, spaces []int) string {
	n_sp := len(spaces)
	cur := 0
	ans := []string{}
	for i := range s {
		if cur == n_sp || i != spaces[cur] {
			ans = append(ans, string(s[i]))
		} else if cur != n_sp {
			ans = append(ans, " "+string(s[i]))
			cur++
		}
	}
	return strings.Join(ans, "")
}

// @lc code=end

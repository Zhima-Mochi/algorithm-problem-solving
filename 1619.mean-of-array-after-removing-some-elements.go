/*
 * @lc app=leetcode id=1619 lang=golang
 *
 * [1619] Mean of Array After Removing Some Elements
 */
package main

import "sort"

// @lc code=start
func trimMean(arr []int) float64 {

	sort.Ints(arr)
	w := len(arr)
	rem := int(float64(w) * 0.05)
	var res int
	for i := rem; i < w-rem; i++ {
		res += arr[i]
	}
	return float64(res) / float64(w-2*rem)
}

// @lc code=end

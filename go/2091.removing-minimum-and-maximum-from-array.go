/*
 * @lc app=leetcode id=2091 lang=golang
 *
 * [2091] Removing Minimum and Maximum From Array
 */
package main

// @lc code=start
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func minimumDeletions(nums []int) int {
	n := len(nums)
	mx_idx := 0
	mn_idx := 0
	for i := range nums {
		if nums[i] < nums[mn_idx] {
			mn_idx = i
		}
		if nums[i] > nums[mx_idx] {
			mx_idx = i
		}
	}
	ans := n
	if val := max(mx_idx, mn_idx) + 1; ans > val {
		ans = val
	}
	if val := n - min(mx_idx, mn_idx); ans > val {
		ans = val
	}
	if val := n - max(mx_idx, mn_idx) + min(mx_idx, mn_idx) + 1; ans > val {
		ans = val
	}
	return ans
}

// @lc code=end

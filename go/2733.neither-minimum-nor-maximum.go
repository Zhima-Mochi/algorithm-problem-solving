/*
 * @lc app=leetcode id=2733 lang=golang
 *
 * [2733] Neither Minimum nor Maximum
 */
package main

// @lc code=start
func findNonMinOrMax(nums []int) int {
	n := len(nums)
	if n <= 2 {
		return -1
	}
	for i := range nums {
		if nums[i] < nums[0] {
			nums[i], nums[0] = nums[0], nums[i]
		}
		if nums[i] > nums[n-1] {
			nums[i], nums[n-1] = nums[n-1], nums[i]
		}
	}
	if nums[1] != nums[0] && nums[1] != nums[n-1] {
		return nums[1]
	}
	return -1
}

// @lc code=end

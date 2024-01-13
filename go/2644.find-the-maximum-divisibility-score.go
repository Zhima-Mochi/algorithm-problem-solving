/*
 * @lc app=leetcode id=2644 lang=golang
 *
 * [2644] Find the Maximum Divisibility Score
 */
package main

// @lc code=start
func maxDivScore(nums []int, divisors []int) int {
	mx := 0
	ans := divisors[0]
	for _, d := range divisors {
		cnt := 0
		for _, n := range nums {
			if n%d == 0 {
				cnt += 1
			}
		}
		if cnt > mx {
			mx = cnt
			ans = d
		} else if cnt == mx {
			if d < ans {
				ans = d
			}
		}
	}
	return ans
}

// @lc code=end

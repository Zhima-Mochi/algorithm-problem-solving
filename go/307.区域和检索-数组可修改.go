/*
 * @lc app=leetcode.cn id=307 lang=golang
 *
 * [307] 区域和检索 - 数组可修改
 */
package main

import "math"

// @lc code=start
type NumArray struct {
	nums []int
	sums []int
	size int
}

func Constructor(nums []int) NumArray {
	na := NumArray{
		nums: nums,
	}
	n := len(nums)
	na.size = int(math.Sqrt(float64(n)))
	na.sums = make([]int, (n+na.size-1)/na.size)
	for i, num := range nums {
		na.sums[i/na.size] += num
	}
	return na
}

func (this *NumArray) Update(index int, val int) {
	this.sums[index/this.size] += val - this.nums[index]
	this.nums[index] = val
}

func (this *NumArray) SumRange(left int, right int) int {
	if right-left < this.size {
		ans := 0
		for i := left; i <= right; i++ {
			ans += this.nums[i]
		}
		return ans
	}
	l := left / this.size
	if left%this.size != 0 {
		l++
	}
	r := right / this.size
	if right%this.size == this.size-1 {
		r++
	}
	ans := 0
	for i := l; i != r; i++ {
		ans += this.sums[i]
	}
	for i := left; i%this.size != 0; i++ {
		ans += this.nums[i]
	}
	for i := right; i%this.size != this.size-1; i-- {
		ans += this.nums[i]
	}
	return ans
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(index,val);
 * param_2 := obj.SumRange(left,right);
 */
// @lc code=end

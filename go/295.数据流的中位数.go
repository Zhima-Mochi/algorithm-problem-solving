/*
 * @lc app=leetcode.cn id=295 lang=golang
 *
 * [295] 数据流的中位数
 */
package main

import (
	"container/heap"
	"sort"
)

// @lc code=start
type hp struct {
	sort.IntSlice
}

func (h *hp) Push(v interface{}) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() interface{} {
	old := h.IntSlice
	v := old[len(old)-1]
	h.IntSlice = old[:len(old)-1]
	return v
}

type MedianFinder struct {
	queMin, queMax hp
}

func Constructor() MedianFinder {
	return MedianFinder{}
}

func (this *MedianFinder) AddNum(num int) {
	mx, mn := &this.queMax, &this.queMin
	if mn.Len() == 0 || num <= -mn.IntSlice[0] {
		heap.Push(mn, -num)
		if mx.Len()+1 < mn.Len() {
			heap.Push(mx, -heap.Pop(mn).(int))
		}
	} else {
		heap.Push(mx, num)
		if mx.Len() > mn.Len() {
			heap.Push(mn, -heap.Pop(mx).(int))
		}
	}
}

func (this *MedianFinder) FindMedian() float64 {
	mx, mn := &this.queMax, &this.queMin
	if mx.Len() < mn.Len() {
		return float64(-mn.IntSlice[0])
	} else {
		return float64(mx.IntSlice[0]-mn.IntSlice[0]) / 2
	}
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
// @lc code=end

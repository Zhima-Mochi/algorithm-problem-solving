/*
 * @lc app=leetcode id=2294 lang=golang
 *
 * [2294] Partition Array Such That Maximum Difference Is K
 */
package main

import (
	"container/heap"
	"sort"
)

// @lc code=start
type PriorityQueue []int

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] > pq[j]
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(int)
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
	item := (*pq)[len(*pq)-1]
	*pq = (*pq)[:len(*pq)-1]
	return item
}
func partitionArray(nums []int, k int) int {
	pq := PriorityQueue{}
	heap.Init(&pq)

	sort.Ints(nums)
	ans := 0
	for _, num := range nums {
		for pq.Len() > 0 && num-pq[len(pq)-1] > k {
			heap.Pop(&pq)
		}
		if pq.Len() == 0 {
			ans += 1
			heap.Push(&pq, num)
		}
	}
	return ans
}

// @lc code=end

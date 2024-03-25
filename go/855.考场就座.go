/*
 * @lc app=leetcode.cn id=855 lang=golang
 *
 * [855] 考场就座
 */
package main

import (
	"container/list"
)

// @lc code=start
type ExamRoom struct {
	N    int
	list *list.List
}

func Constructor(n int) ExamRoom {
	return ExamRoom{
		N:    n,
		list: list.New(),
	}
}

func (this *ExamRoom) Seat() int {
	if this.list.Len() == 0 {
		this.list.PushBack(0)
		return 0
	}

	prev := 0
	maxAfterNode := this.list.Front()
	maxDist := maxAfterNode.Value.(int)
	maxPos := 0

	for cur := maxAfterNode.Next(); cur != nil; cur = cur.Next() {
		pos := cur.Value.(int)
		if (pos-prev)/2 > maxDist {
			maxDist = (pos - prev) / 2
			maxPos = prev + maxDist
			maxAfterNode = cur
		}
		prev = pos
	}

	if this.N-1-prev > maxDist {
		maxPos = this.N - 1
		maxAfterNode = nil
	}

	if maxAfterNode != nil {
		this.list.InsertBefore(maxPos, maxAfterNode)
	} else {
		this.list.PushBack(maxPos)
	}

	return maxPos
}

func (this *ExamRoom) Leave(p int) {
	for cur := this.list.Front(); cur != nil; cur = cur.Next() {
		if cur.Value.(int) == p {
			this.list.Remove(cur)
			break
		}
	}
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Seat();
 * obj.Leave(p);
 */
// @lc code=end

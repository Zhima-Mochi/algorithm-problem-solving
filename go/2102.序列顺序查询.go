/*
 * @lc app=leetcode.cn id=2102 lang=golang
 *
 * [2102] 序列顺序查询
 */
package main

import (
	"container/heap"
)

// @lc code=start

type pair struct {
	score int
	name  string
}

type hp struct {
	pairs []pair
}

func (hp *hp) Len() int {
	return len(hp.pairs)
}

func (hp *hp) Swap(i, j int) {
	hp.pairs[i], hp.pairs[j] = hp.pairs[j], hp.pairs[i]
}

func (hp *hp) Less(i, j int) bool {
	if hp.pairs[i].score > hp.pairs[j].score {
		return true
	}
	if hp.pairs[i].score < hp.pairs[j].score {
		return false
	}

	if hp.pairs[i].score > 0 {
		return hp.pairs[i].name < hp.pairs[j].name
	}
	return hp.pairs[i].name >= hp.pairs[j].name
}

func (hp *hp) Push(v any) {
	hp.pairs = append(hp.pairs, v.(pair))
}

func (hp *hp) Pop() any {
	n := len(hp.pairs)
	ret := hp.pairs[n-1]
	hp.pairs = hp.pairs[:n-1]
	return ret
}

type SORTracker struct {
	minHeap, maxHeap hp
	queryCount       int
}

func Constructor() SORTracker {
	return SORTracker{
		queryCount: 1,
	}
}

func (this *SORTracker) Add(name string, score int) {
	if this.minHeap.Len() == 0 {
		heap.Push(&this.minHeap, pair{score: -score, name: name})
		return
	}
	if -this.minHeap.pairs[0].score < score || -this.minHeap.pairs[0].score == score && this.minHeap.pairs[0].name >= name {
		heap.Push(&this.minHeap, pair{score: -score, name: name})
		return
	}
	heap.Push(&this.maxHeap, pair{score: score, name: name})
}

func (this *SORTracker) Get() string {
	for this.minHeap.Len() < this.queryCount {
		elem := heap.Pop(&this.maxHeap).(pair)
		elem.score *= -1
		heap.Push(&this.minHeap, elem)
	}
	for this.minHeap.Len() > this.queryCount {
		elem := heap.Pop(&this.minHeap).(pair)
		elem.score *= -1
		heap.Push(&this.maxHeap, elem)
	}
	ret := this.minHeap.pairs[0].name
	this.queryCount++
	return ret
}

/**
 * Your SORTracker object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(name,score);
 * param_2 := obj.Get();
 */
// @lc code=end

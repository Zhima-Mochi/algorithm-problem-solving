/*
 * @lc app=leetcode.cn id=2276 lang=golang
 *
 * [2276] 统计区间中的整数数目
 */
package main

import (
	"github.com/emirpasic/gods/trees/redblacktree"
)

// @lc code=start
type CountIntervals struct {
	*redblacktree.Tree
	count int
}

func Constructor() CountIntervals {
	return CountIntervals{Tree: redblacktree.NewWithIntComparator()}
}

func (this *CountIntervals) Add(left int, right int) {
	removedKeys := []int{}
	cur := this.Iterator()
	ok := cur.Next()
	if node, ok := this.Tree.Floor(left); ok {
		cur = this.IteratorAt(node)
		ok = true
	}

	for ; ok; ok = cur.Next() {
		l := cur.Key().(int)
		r := cur.Value().(int)

		if r < left {
			continue
		}
		if l > right {
			break
		}

		removedKeys = append(removedKeys, l)

		if l < left {
			left = l
		}
		if r > right {
			right = r
			break
		}
	}

	for _, k := range removedKeys {
		node := this.GetNode(k)
		this.count -= node.Value.(int) - node.Key.(int) + 1
		this.Remove(k)
	}

	this.count += right - left + 1
	this.Put(left, right)
}

func (this *CountIntervals) Count() int {
	return this.count
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(left,right);
 * param_2 := obj.Count();
 */
// @lc code=end

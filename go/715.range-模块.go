/*
 * @lc app=leetcode.cn id=715 lang=golang
 *
 * [715] Range 模块
 */
package main

import "github.com/emirpasic/gods/trees/redblacktree"

// @lc code=start
type RangeModule struct {
	covers *redblacktree.Tree
}

func Constructor() RangeModule {
	return RangeModule{
		covers: redblacktree.NewWithIntComparator(),
	}
}
func (this *RangeModule) AddRange(left int, right int) {
	toRemove := []int{}

	iter := this.covers.Iterator()
	if node, ok := this.covers.Floor(left); ok {
		iter = this.covers.IteratorAt(node)
	} else if node, ok := this.covers.Ceiling(left); ok {
		iter = this.covers.IteratorAt(node)
	} else {
		this.covers.Put(left, right)
		return
	}

	for ok := true; ok; ok = iter.Next() {
		k := iter.Key().(int)
		v := iter.Value().(int)

		if v < left {
			continue
		}
		if k > right {
			break
		}

		toRemove = append(toRemove, k)
		if k < left && v >= left {
			left = k
		}
		if k <= right && v > right {
			right = v
			break
		}
	}

	for _, k := range toRemove {
		this.covers.Remove(k)
	}
	this.covers.Put(left, right)
}

func (this *RangeModule) QueryRange(left int, right int) bool {
	if node, ok := this.covers.Floor(left); ok {
		if node.Value.(int) >= right {
			return true
		}
	}
	return false
}

func (this *RangeModule) RemoveRange(left int, right int) {
	var toAdd [][2]int
	var toRemove []int

	iter := this.covers.Iterator()
	if node, ok := this.covers.Floor(left); ok {
		iter = this.covers.IteratorAt(node)
	} else if node, ok := this.covers.Ceiling(left); ok {
		iter = this.covers.IteratorAt(node)
	} else {
		return
	}

	for ok := true; ok; ok = iter.Next() {
		k := iter.Key().(int)
		v := iter.Value().(int)
		if v <= left {
			continue
		}
		if k >= right {
			break
		}

		toRemove = append(toRemove, k)
		if k < left && v > left {
			toAdd = append(toAdd, [2]int{k, left})
		}
		if k < right && v > right {
			toAdd = append(toAdd, [2]int{right, v})
		}
	}

	for _, k := range toRemove {
		this.covers.Remove(k)
	}
	for _, kv := range toAdd {
		this.covers.Put(kv[0], kv[1])
	}
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddRange(left,right);
 * param_2 := obj.QueryRange(left,right);
 * obj.RemoveRange(left,right);
 */
// @lc code=end

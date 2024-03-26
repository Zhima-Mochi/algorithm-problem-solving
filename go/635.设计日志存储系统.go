/*
 * @lc app=leetcode.cn id=635 lang=golang
 *
 * [635]
 */
package main

import (
	"strings"

	"github.com/emirpasic/gods/trees/redblacktree"
)

// @lc code=start

var (
	granToInt = map[string]int{
		"Year":   1,
		"Month":  2,
		"Day":    3,
		"Hour":   4,
		"Minute": 5,
		"Second": 6,
	}
)

func transform(gran int, timestamp string, isFloor bool) string {
	t := strings.Split(timestamp, ":")
	for i, s := range t {
		if i >= gran {
			c := "9"
			if isFloor {
				c = "0"
			}
			t[i] = strings.Repeat(c, len(s))
		}
	}
	return strings.Join(t, ":")
}

type LogSystem struct {
	Tree *redblacktree.Tree
}

func Constructor() LogSystem {
	return LogSystem{
		Tree: redblacktree.NewWithStringComparator(),
	}
}

func (this *LogSystem) Put(id int, timestamp string) {
	this.Tree.Put(timestamp, id)
}

func (this *LogSystem) Retrieve(start string, end string, granularity string) []int {
	start = transform(granToInt[granularity], start, true)
	end = transform(granToInt[granularity], end, false)
	iterStart := this.Tree.Iterator()
	iterStart.First()
	iterEnd := this.Tree.Iterator()
	iterEnd.End()

	if node, found := this.Tree.Floor(start); found {
		iterStart = this.Tree.IteratorAt(node)
		if iterStart.Key().(string) < start {
			iterStart.Next()
		}
	}
	if node, found := this.Tree.Ceiling(end); found {
		iterEnd = this.Tree.IteratorAt(node)
		if iterEnd.Key().(string) == end {
			iterEnd.Next()
		}
	}
	ans := []int{}
	for cur := iterStart; cur != iterEnd; cur.Next() {
		ans = append(ans, cur.Value().(int))
	}

	return ans
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(id,timestamp);
 * param_2 := obj.Retrieve(start,end,granularity);
 */
// @lc code=end

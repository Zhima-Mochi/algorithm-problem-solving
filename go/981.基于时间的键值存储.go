/*
 * @lc app=leetcode.cn id=981 lang=golang
 *
 * [981] 基于时间的键值存储
 */
package main

import "sort"

// @lc code=start
type Node struct {
	timestamp int
	val       string
}
type TimeMap struct {
	keyTimeValuesMap map[string][]*Node
}

func Constructor() TimeMap {
	return TimeMap{
		keyTimeValuesMap: map[string][]*Node{},
	}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
	if _, ok := this.keyTimeValuesMap[key]; !ok {
		this.keyTimeValuesMap[key] = []*Node{}
	}
	this.keyTimeValuesMap[key] = append(this.keyTimeValuesMap[key], &Node{timestamp: timestamp, val: value})
}

func (this *TimeMap) Get(key string, timestamp int) string {
	if _, ok := this.keyTimeValuesMap[key]; !ok {
		return ""
	}
	i := sort.Search(len(this.keyTimeValuesMap[key]), func(i int) bool { return this.keyTimeValuesMap[key][i].timestamp > timestamp }) - 1
	if i == -1 {
		return ""
	}
	return this.keyTimeValuesMap[key][i].val
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */
// @lc code=end

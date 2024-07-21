/*
 * @lc app=leetcode.cn id=460 lang=golang
 *
 * [460] LFU 缓存
 */
package main

import (
	"container/list"
)

// @lc code=start

type Node struct {
	key  int
	val  int
	freq int
}

type LFUCache struct {
	capacity int
	minFreq  int
	kv       map[int]*list.Element
	FreqKey  map[int]*list.List
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		capacity: capacity,
		FreqKey:  map[int]*list.List{},
		kv:       map[int]*list.Element{},
	}
}

func (this *LFUCache) Get(key int) int {
	if this.capacity == 0 {
		return -1
	}
	ret := -1
	if iter, ok := this.kv[key]; ok {
		ret = iter.Value.(Node).val
		this.addCount(key)
	}

	return ret
}

func (this *LFUCache) addCount(key int) {
	f := this.kv[key].Value.(Node).freq + 1
	node := Node{
		key:  key,
		val:  this.kv[key].Value.(Node).val,
		freq: f,
	}

	if this.FreqKey[f] == nil {
		this.FreqKey[f] = list.New()
	}

	this.kv[key] = this.FreqKey[f].PushBack(node)
}

func (this *LFUCache) Put(key int, value int) {
	if this.capacity == 0 {
		return
	}

	iter := this.kv[key]
	if iter == nil {
		if len(this.kv) == this.capacity {

		}
	}

	this.kv[key] = value
	this.addCount(key)

}

/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

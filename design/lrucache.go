package main

import (
	"container/list"
	"fmt"
)

type LRUCache struct {
	size     int
	capacity int
	cache    map[int]*list.Element
	ls       *list.List
}

func Constructor(capacity int) LRUCache {
	l := LRUCache{
		cache:    map[int]*list.Element{},
		capacity: capacity,
	}

	l.ls = list.New()

	return l
}

func (this *LRUCache) Get(key int) int {
	if _, ok := this.cache[key]; !ok {
		return -1
	}
	node := this.cache[key]
	this.ls.MoveToFront(node)
	return node.Value.(int)
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.cache[key]; !ok {
		node := this.ls.PushFront(value)
		this.cache[key] = node
		this.size++
		if this.size > this.capacity {
			removed := this.ls.Back()
			this.ls.Remove(removed)
			delete(this.cache, removed.Value.(int))
			this.size--
		}
	} else {
		node := this.cache[key]
		node.Value = value
		this.ls.MoveToFront(node)
	}
}

func main() {
	lru := Constructor(2)
	lru.Put(1, 1)
	lru.Put(2, 2)
	fmt.Println(lru.Get(1)) // should return 1
	lru.Put(3, 3)           // evicts key 2
	fmt.Println(lru.Get(2)) // should return -1 (not found)
	lru.Put(4, 4)           // evicts key 1
	fmt.Println(lru.Get(1)) // should return -1 (not found)
	fmt.Println(lru.Get(3)) // should return 3
	fmt.Println(lru.Get(4)) // should return 4
}

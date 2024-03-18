/*
 * @lc app=leetcode.cn id=707 lang=golang
 *
 * [707] 设计链表
 */
package main

// @lc code=start
type Node struct {
	prev, next *Node
	val        int
}

type MyLinkedList struct {
	size       int
	head, tail *Node
}

func Constructor() MyLinkedList {
	head := new(Node)
	tail := new(Node)
	head.next = tail
	tail.prev = head
	return MyLinkedList{
		size: 0,
		head: head,
		tail: tail,
	}
}

func (this *MyLinkedList) Get(index int) int {
	if index >= this.size || index < 0 {
		return -1
	}
	cur := this.head
	for i := 0; i <= index; i++ {
		cur = cur.next
	}
	return cur.val
}

func (this *MyLinkedList) AddAtHead(val int) {
	this.AddAtIndex(0, val)
}

func (this *MyLinkedList) AddAtTail(val int) {
	this.AddAtIndex(this.size, val)
}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index > this.size || index < 0 {
		return
	}

	cur := this.toPreIndex(index)
	ogNext := cur.next
	cur.next = &Node{
		val:  val,
		prev: cur,
		next: ogNext,
	}
	ogNext.prev = cur.next
	this.size++
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index >= this.size || index < 0 {
		return
	}
	cur := this.toPreIndex(index)
	cur.next = cur.next.next
	cur.next.prev = cur
	this.size--

}

func (this *MyLinkedList) toPreIndex(index int) *Node {
	var cur *Node
	if index < this.size/2 {
		cur = this.head
		for i := 0; i != index; i++ {
			cur = cur.next
		}
	} else {
		cur = this.tail
		for i := 0; i <= this.size-index; i++ {
			cur = cur.prev
		}
	}
	return cur
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
// @lc code=end

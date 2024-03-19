/*
 * @lc app=leetcode.cn id=622 lang=golang
 *
 * [622] 设计循环队列
 */
package main

// @lc code=start
type MyCircularQueue struct {
	queue       []int
	maxSize     int
	front, rear int
}

func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		queue:   make([]int, k),
		maxSize: k,
		front:   -1,
		rear:    -1,
	}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.IsFull() {
		return false
	}
	if this.IsEmpty() {
		this.front = 0
	}
	this.rear = (this.rear + 1) % this.maxSize
	this.queue[this.rear] = value
	return true
}

func (this *MyCircularQueue) DeQueue() bool {
	if this.IsEmpty() {
		return false
	}
	if this.front == this.rear {
		this.front = -1
		this.rear = -1
	} else {
		this.front = (this.front + 1) % this.maxSize
	}
	return true
}

func (this *MyCircularQueue) Front() int {
	if this.IsEmpty() {
		return -1
	}
	return this.queue[this.front]
}

func (this *MyCircularQueue) Rear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.queue[this.rear]
}

func (this *MyCircularQueue) IsEmpty() bool {
	return this.front == -1
}

func (this *MyCircularQueue) IsFull() bool {
	return ((this.rear + 1) % this.maxSize) == this.front
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.EnQueue(value);
 * param_2 := obj.DeQueue();
 * param_3 := obj.Front();
 * param_4 := obj.Rear();
 * param_5 := obj.IsEmpty();
 * param_6 := obj.IsFull();
 */
// @lc code=end

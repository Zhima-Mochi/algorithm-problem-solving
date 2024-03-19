/*
 * @lc app=leetcode.cn id=232 lang=golang
 *
 * [232] 用栈实现队列
 */
package main

// @lc code=start

type MyQueue struct {
	in, out []int
}

func Constructor() MyQueue {
	return MyQueue{
		in:  []int{},
		out: []int{},
	}
}

func (this *MyQueue) toOut() {
	if len(this.out) > 0 {
		return
	}
	for i := len(this.in) - 1; i != -1; i-- {
		this.out = append(this.out, this.in[i])
	}
	this.in = []int{}
}

func (this *MyQueue) Push(x int) {
	this.in = append(this.in, x)
}

func (this *MyQueue) Pop() int {
	ret := this.Peek()
	this.out = this.out[:len(this.out)-1]
	return ret
}

func (this *MyQueue) Peek() int {
	this.toOut()
	return this.out[len(this.out)-1]
}

func (this *MyQueue) Empty() bool {
	this.toOut()
	return len(this.out) == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
// @lc code=end

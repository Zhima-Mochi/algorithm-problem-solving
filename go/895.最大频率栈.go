/*
 * @lc app=leetcode.cn id=895 lang=golang
 *
 * [895] 最大频率栈
 */
package main

// @lc code=start

type FreqStack struct {
	freqNumsMap map[int][]int
	numFreqMap  map[int]int
	maxFreq     int
}

func Constructor() FreqStack {
	return FreqStack{
		freqNumsMap: map[int][]int{},
		numFreqMap:  map[int]int{},
	}
}

func (this *FreqStack) Push(val int) {
	this.numFreqMap[val]++
	freq := this.numFreqMap[val]
	if freq > this.maxFreq {
		this.maxFreq = freq
	}
	this.freqNumsMap[freq] = append(this.freqNumsMap[freq], val)
}

func (this *FreqStack) Pop() int {
	l := len(this.freqNumsMap[this.maxFreq])
	val := this.freqNumsMap[this.maxFreq][l-1]
	this.numFreqMap[val]--
	this.freqNumsMap[this.maxFreq] = this.freqNumsMap[this.maxFreq][:l-1]
	if l == 1 {
		this.maxFreq--
	}
	return val
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * param_2 := obj.Pop();
 */
// @lc code=end

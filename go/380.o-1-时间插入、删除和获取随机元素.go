/*
 * @lc app=leetcode.cn id=380 lang=golang
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
package main

import (
	"math/rand"
	"time"
)

// @lc code=start

type RandomizedSet struct {
	valPos map[int]int
	valArr []int
}

func Constructor() RandomizedSet {
	rand.Seed(time.Now().UnixNano())
	return RandomizedSet{
		valPos: map[int]int{},
		valArr: []int{},
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.valPos[val]; ok {
		return false
	}
	this.valPos[val] = len(this.valArr)
	this.valArr = append(this.valArr, val)
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.valPos[val]; !ok {
		return false
	}
	tailVal := this.valArr[len(this.valArr)-1]
	targePos := this.valPos[val]
	this.valArr[targePos] = tailVal
	this.valArr = this.valArr[:len(this.valArr)-1]
	this.valPos[tailVal] = targePos
	delete(this.valPos, val)
	return true
}

func (this *RandomizedSet) GetRandom() int {
	return this.valArr[rand.Intn(len(this.valArr))]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
// @lc code=end

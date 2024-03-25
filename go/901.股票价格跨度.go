/*
 * @lc app=leetcode.cn id=901 lang=golang
 *
 * [901] 股票价格跨度
 */
package main

// @lc code=start
type StockSpanner struct {
	day          int
	decrStkDay   []int
	decrStkPrice []int
}

func Constructor() StockSpanner {
	return StockSpanner{
		decrStkDay:   []int{},
		decrStkPrice: []int{},
	}
}

func (this *StockSpanner) Next(price int) int {
	for len(this.decrStkDay) > 0 && this.decrStkPrice[len(this.decrStkPrice)-1] <= price {
		this.decrStkDay = this.decrStkDay[:len(this.decrStkDay)-1]
		this.decrStkPrice = this.decrStkPrice[:len(this.decrStkPrice)-1]
	}
	ans := 0
	if len(this.decrStkDay) > 0 {
		ans = this.day - this.decrStkDay[len(this.decrStkDay)-1]
	} else {
		ans = this.day + 1
	}
	this.decrStkDay = append(this.decrStkDay, this.day)
	this.decrStkPrice = append(this.decrStkPrice, price)
	this.day++
	return ans
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
// @lc code=end

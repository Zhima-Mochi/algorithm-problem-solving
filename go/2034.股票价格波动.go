/*
 * @lc app=leetcode.cn id=2034 lang=golang
 *
 * [2034] 股票价格波动
 */
package main

// @lc code=start

type StockPrice struct {
	prices       *redblacktree.Tree
	timePriceMap map[int]int
	maxTimestamp int
}

func Constructor() StockPrice {
	return StockPrice{
		redblacktree.NewWithIntComparator(),
		map[int]int{},
		0,
	}
}

func (this *StockPrice) Update(timestamp int, price int) {
	if originalPrice, ok := this.timePriceMap[timestamp]; ok {
		if times, _ := this.prices.Get(originalPrice); times.(int) > 1 {
			this.prices.Put(originalPrice, times.(int)-1)
		} else {
			this.prices.Remove(originalPrice)
		}
	}
	times := 0
	if val, ok := this.prices.Get(price); ok {
		times = val.(int)
	}

	this.timePriceMap[timestamp] = price
	this.prices.Put(price, times+1)
	if timestamp > this.maxTimestamp {
		this.maxTimestamp = timestamp
	}
}

func (this *StockPrice) Current() int {
	return this.timePriceMap[this.maxTimestamp]
}

func (this *StockPrice) Maximum() int {
	return this.prices.Right().Key.(int)
}

func (this *StockPrice) Minimum() int {
	return this.prices.Left().Key.(int)
}

/**
 * Your StockPrice object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Update(timestamp,price);
 * param_2 := obj.Current();
 * param_3 := obj.Maximum();
 * param_4 := obj.Minimum();
 */
// @lc code=end

package main

import (
	"container/heap"
	"fmt"
)

type element struct {
	value int
}

type hp struct {
	elements []element
}

func (h hp) Len() int {
	return len(h.elements)
}

func (h hp) Less(i, j int) bool {
	return h.elements[i].value < h.elements[j].value
}

func (h hp) Swap(i, j int) {
	h.elements[i], h.elements[j] = h.elements[j], h.elements[i]
}

func (h *hp) Push(e any) {
	h.elements = append(h.elements, e.(element))
}

func (h *hp) Pop() any {
	ret := h.elements[len(h.elements)-1]
	h.elements = h.elements[:len(h.elements)-1]
	return ret
}

type QuantileFinder struct {
	minHeap, maxHeap hp
	q                int // 0 - 100
	cnt              int
}

func Constructor(q int) QuantileFinder {
	return QuantileFinder{
		q: q,
	}
}

func (this *QuantileFinder) Add(val int) {
	if len(this.maxHeap.elements) == 0 || -val >= -this.maxHeap.elements[0].value {
		heap.Push(&this.maxHeap, element{-val})
	} else {
		heap.Push(&this.minHeap, element{val})
	}
	this.cnt++

	if float64(len(this.maxHeap.elements)) < float64(this.q*this.cnt)/100 {
		e := heap.Pop(&this.minHeap).(element)
		e.value = -e.value
		heap.Push(&this.maxHeap, e)
	} else if float64(len(this.maxHeap.elements)) > float64(this.q*this.cnt)/100 {
		e := heap.Pop(&this.maxHeap).(element)
		e.value = -e.value
		heap.Push(&this.minHeap, e)
	}

}

func (this *QuantileFinder) Find() float64 {
	if this.q == 0 {
		return float64(this.minHeap.elements[0].value)
	}

	if this.q == 100 {
		return float64(-this.maxHeap.elements[0].value)
	}

	if this.q*this.cnt%100 == 0 {
		return float64(-this.maxHeap.elements[0].value+this.minHeap.elements[0].value) / 2
	}

	return float64(-this.maxHeap.elements[0].value)
}

func main() {
	qf := Constructor(50)
	qf.Add(1)
	qf.Add(2)
	qf.Add(3)
	qf.Add(4)
	qf.Add(5)

	fmt.Println(qf.maxHeap.elements)
	fmt.Println(qf.minHeap.elements)

	fmt.Println(qf.Find())

	qf.Add(6)

	fmt.Println(qf.Find())

	// 0
	qf = Constructor(0)
	qf.Add(1)
	qf.Add(2)

	fmt.Println(qf.Find())

	// 100
	qf = Constructor(100)
	qf.Add(1)
	qf.Add(2)

	fmt.Println(qf.Find())
}

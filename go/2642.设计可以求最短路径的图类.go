/*
 * @lc app=leetcode.cn id=2642 lang=golang
 *
 * [2642] 设计可以求最短路径的图类
 */
package main

import "container/heap"

// @lc code=start
type Graph struct {
	costs [][]int
}

const (
	BOUND = 1000001
)

func Constructor(n int, edges [][]int) Graph {
	ret := Graph{}
	ret.costs = make([][]int, n)
	for i := 0; i != n; i++ {
		ret.costs[i] = make([]int, n)
		for j := 0; j != n; j++ {
			ret.costs[i][j] = BOUND

		}
	}

	for _, edge := range edges {
		ret.costs[edge[0]][edge[1]] = edge[2]
	}

	return ret
}

func (this *Graph) AddEdge(edge []int) {
	this.costs[edge[0]][edge[1]] = edge[2]
}

type priorityqueue [][2]int

func (pq priorityqueue) Len() int {
	return len(pq)
}

func (pq priorityqueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq priorityqueue) Less(i, j int) bool {
	return pq[i][1] < pq[j][1]
}

func (pq *priorityqueue) Push(v any) {
	*pq = append(*pq, v.([2]int))
}

func (pq *priorityqueue) Pop() any {
	old := *pq
	n := len(old)
	ret := old[n-1]
	*pq = old[:n-1]
	return ret
}

func (this *Graph) ShortestPath(node1 int, node2 int) int {
	if node1 == node2 {
		return 0
	}
	pq := priorityqueue{}
	heap.Push(&pq, [2]int{node1, 0})
	seen := map[int]struct{}{}
	for pq.Len() > 0 {
		arr := heap.Pop(&pq).([2]int)
		node := arr[0]
		cost := arr[1]
		seen[node] = struct{}{}
		if node == node2 {
			return cost
		}
		for next, addCost := range this.costs[node] {
			if _, ok := seen[next]; addCost != BOUND && !ok {
				heap.Push(&pq, [2]int{next, cost + addCost})
			}
		}
	}
	return -1
}

/**
 * Your Graph object will be instantiated and called as such:
 * obj := Constructor(n, edges);
 * obj.AddEdge(edge);
 * param_2 := obj.ShortestPath(node1,node2);
 */
// @lc code=end

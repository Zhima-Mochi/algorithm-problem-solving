#
# @lc app=leetcode id=2642 lang=python3
#
# [2642] Design Graph With Shortest Path Calculator
#
from typing import *
from math import *
from heapq import *

# @lc code=start


class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.minDistances = [[inf]*n for _ in range(n)]
        for i in range(n):
            self.minDistances[i][i] = 0
        self.pq = []
        self.n = n
        for edge in edges:
            self.addEdge(edge)

    def addEdge(self, edge: List[int]) -> None:
        if self.minDistances[edge[0]][edge[1]] > edge[2]:
            self.minDistances[edge[0]][edge[1]] = edge[2]

    def shortestPath(self, node1: int, node2: int) -> int:
        pq = [(0, node1)]
        seen = set()
        while pq:
            dist, src = heappop(pq)
            if src == node2:
                self.minDistances[node1][node2] = dist
                return self.minDistances[node1][node2]
            seen.add(src)
            for dst in range(self.n):
                if dst in seen or self.minDistances[src][dst] == inf:
                    continue
                heappush(pq, (dist+self.minDistances[src][dst], dst))
        return -1


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)``
# @lc code=end

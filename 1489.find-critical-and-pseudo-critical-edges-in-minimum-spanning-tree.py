#
# @lc app=leetcode id=1489 lang=python3
#
# [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
#

# @lc code=start


class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.size = [1] * n
        self.n = n
        self.setCount = n
    
    def findset(self, x: int) -> int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.findset(self.parent[x])
        return self.parent[x]
    
    def unite(self, x: int, y: int) -> bool:
        x, y = self.findset(x), self.findset(y)
        if x == y:
            return False
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.parent[y] = x
        self.size[x] += self.size[y]
        self.setCount -= 1
        return True

class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        m = len(edges)
        for i, edge in enumerate(edges):
            edge.append(i)
        edges.sort(key=lambda x: x[2])

        uf_all = UnionFind(n)
        value = 0
        for i in range(m):
            if uf_all.unite(edges[i][0], edges[i][1]):
                value += edges[i][2]

        ans = [list(), list()]
        
        for i in range(m):
            uf = UnionFind(n)
            v = 0
            for j in range(m):
                if i != j and uf.unite(edges[j][0], edges[j][1]):
                    v += edges[j][2]
            if uf.setCount != 1 or (uf.setCount == 1 and v > value):
                ans[0].append(edges[i][3])
                continue

            uf = UnionFind(n)
            uf.unite(edges[i][0], edges[i][1])
            v = edges[i][2]
            for j in range(m):
                if i != j and uf.unite(edges[j][0], edges[j][1]):
                    v += edges[j][2]
            if v == value:
                ans[1].append(edges[i][3])
      
        return ans



# @lc code=end

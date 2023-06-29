#
# @lc app=leetcode id=1514 lang=python3
#
# [1514] Path with Maximum Probability
#

# @lc code=start
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        # priority queue
        pq = [(-1, start)]
        # visited
        visited = set()
        # graph
        graph = collections.defaultdict(list)
        # build graph
        for i, (u, v) in enumerate(edges):
            graph[u].append((v, succProb[i]))
            graph[v].append((u, succProb[i]))
        # dijkstra
        while pq:
            prob, node = heapq.heappop(pq)
            if node == end:
                return -prob
            if node in visited:
                continue
            visited.add(node)
            for nei, nei_prob in graph[node]:
                if nei not in visited:
                    heapq.heappush(pq, (prob * nei_prob, nei))
        return 0

        
# @lc code=end

#
# @lc app=leetcode id=1192 lang=python3
#
# [1192] Critical Connections in a Network
#
from collections import defaultdict
# @lc code=start

# t:O(V+E), s:O(V+E)

class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        connect = defaultdict(list)
        for con in connections:
            connect[con[0]].append(con[1])
            connect[con[1]].append(con[0])
        parent = [-1]*n
        seen_time = [-1]*n
        lowest = [None]*n
        res = []
        self.time_count = 0

        def findBridge(node):
            seen_time[node] = self.time_count
            lowest[node] = self.time_count
            self.time_count += 1
            for child in connect[node]:
                if seen_time[child] == -1:
                    parent[child] = node
                    findBridge(child)
                    lowest[node] = min(lowest[node], lowest[child])
                    if lowest[child] > seen_time[node]:
                        res.append([node, child])
                elif child != parent[node]:
                    lowest[node] = min(lowest[node], seen_time[child])

        for i in range(n):
            if seen_time[i] == -1:
                findBridge(i)
        return res


# @lc code=end

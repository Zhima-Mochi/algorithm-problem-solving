#
# @lc app=leetcode id=815 lang=python3
#
# [815] Bus Routes
#
from typing import *
from collections import *
from math import *
from heapq import *
# @lc code=start


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        s_routes = defaultdict(list)
        n = len(routes)
        connected = [[False]*n for _ in range(n)]
        for r1, route in enumerate(routes):
            for site in route:
                for r2 in s_routes[site]:
                    connected[r1][r2] = connected[r2][r1] = True
                s_routes[site].append(r1)
        if not s_routes[target]:
            return -1
        dists = [inf]*n
        q = deque(s_routes[source])
        for r in s_routes[source]:
            dists[r] = 1
        while q:
            r1 = q.popleft()
            for r2 in range(n):
                if connected[r1][r2] and dists[r2] == inf:
                    dists[r2] = dists[r1]+1
                    q.append(r2)
        res = min((dists[r] for r in s_routes[target]))
        if res == inf:
            return -1
        return res


# @lc code=end

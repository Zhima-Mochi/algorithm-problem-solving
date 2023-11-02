#
# @lc app=leetcode id=2127 lang=python3
#
# [2127] Maximum Employees to Be Invited to a Meeting
#
from typing import *
from collections import *
# @lc code=start

# t:O(n), s:O(n)
class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        indeg = [0] * n
        for i in range(n):
            indeg[favorite[i]] += 1

        seen = [False]*n
        records = [1]*n
        q = deque(i for i in range(n) if indeg[i] == 0)
        while q:
            u = q.popleft()
            seen[u] = True
            v = favorite[u]
            records[v] = max(records[v], records[u]+1)
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
        ring = 0
        total = 0
        for i in range(n):
            if not seen[i]:
                j = favorite[i]
                if favorite[j] == i:
                    total += records[i]+records[j]
                    seen[i] = seen[j] = True
                else:
                    u = i
                    cnt = 0
                    while True:
                        cnt += 1
                        u = favorite[u]
                        seen[u] = True
                        if u == i:
                            break
                    ring = max(ring, cnt)
        return max(ring, total)

# @lc code=end

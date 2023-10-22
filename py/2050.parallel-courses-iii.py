#
# @lc app=leetcode id=2050 lang=python3
#
# [2050] Parallel Courses III
#
from typing import *
from collections import *
# @lc code=start

# t:O(m+n), s:O(m+n)
class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        graphs = defaultdict(list)
        degrees = [0]*n
        curTimes = [0]*n
        for rel in relations:
            graphs[rel[0]].append(rel[1])
            degrees[rel[1]-1] += 1
        q = deque()
        for i in range(n):
            if degrees[i] == 0:
                curTimes[i] = time[i]
                q.append(i+1)
        while q:
            cur = q.popleft()
            for next in graphs[cur]:
                curTimes[next-1] = max(curTimes[next-1],
                                       curTimes[cur-1]+time[next-1])
                degrees[next-1] -= 1
                if degrees[next-1] == 0:
                    q.append(next)

        return max(curTimes)

# @lc code=end

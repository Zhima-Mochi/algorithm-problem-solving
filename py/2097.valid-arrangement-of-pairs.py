#
# @lc app=leetcode id=2097 lang=python3
#
# [2097] Valid Arrangement of Pairs
#
from typing import *
from collections import *
# @lc code=start

# t:O(n), s:O(n)
class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        edges = defaultdict(list)
        pCnt, cCnt = Counter(), Counter()
        for x, y in pairs:
            edges[x].append(y)
            pCnt[y] += 1
            cCnt[x] += 1
        
       
        start = pairs[0][0]
        for x in cCnt:
            if cCnt[x] == pCnt[x] + 1:
                start = x
                break
        res = list()
        
        def dfs(u: int) -> None:
            while edges[u]:
                v = edges[u].pop()
                dfs(v)
                res.append([u, v])
        
        dfs(start)
        return res[::-1]



# @lc code=end

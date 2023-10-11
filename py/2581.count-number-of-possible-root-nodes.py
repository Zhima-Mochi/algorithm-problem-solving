#
# @lc app=leetcode id=2581 lang=python3
#
# [2581] Count Number of Possible Root Nodes
#
from collections import *
from typing import *
# @lc code=start

# t:O(n+m), s:O(n+m)
class Solution:
    def rootCount(self, edges: List[List[int]], guesses: List[List[int]], k: int) -> int:
        graphs = defaultdict(list)
        for edge in edges:
            graphs[edge[0]].append(edge[1])
            graphs[edge[1]].append(edge[0])
        guess_set = set()
        for guess in guesses:
            guess_set.add(guess[0]*1000000+guess[1])
        res = 0
        n = len(edges)+1
        guess_n = len(guesses)
        memo = defaultdict(int)

        def dfs(parent, child) -> int:
            key = parent*1000000+child
            nkey = child*1000000+parent
            if key in memo:
                return memo[key]
            ncorrect = 0
            if nkey in guess_set:
                ncorrect += 1
            for nc in graphs[child]:
                if nc == parent:
                    continue
                ncorrect += dfs(child, nc)
            memo[key] = ncorrect
            return memo[key]

        for i in range(n):
            ncorrect = 0
            for child in graphs[i]:
                ncorrect += dfs(i, child)
            if ncorrect <= guess_n-k:
                res += 1
        return res


# @lc code=end

#
# @lc app=leetcode id=2603 lang=python3
#
# [2603] Collect Coins in a Tree
#
from collections import defaultdict, deque
# @lc code=start


class Solution:
    def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
        n = len(coins)
        graphs = defaultdict(list)
        degree = [0]*n
        for a, b in edges:
            graphs[a].append(b)
            graphs[b].append(a)
            degree[a] += 1
            degree[b] += 1
        rest_coins = n
        q = deque(i for i in range(n) if degree[i] == 1 and coins[i] == 0)
        while q:
            node = q.popleft()
            degree[node] -= 1
            rest_coins -= 1
            for nb in graphs[node]:
                degree[nb] -= 1
                if degree[nb] == 1 and coins[nb] == 0:
                    q.append(nb)
        for _ in range(2):
            q = deque(i for i in range(n) if degree[i] == 1)
            while q:
                node = q.popleft()
                degree[node] -= 1
                rest_coins -= 1
                for nb in graphs[node]:
                    degree[nb] -= 1
        return 0 if rest_coins == 0 else (rest_coins-1)*2

# @lc code=end

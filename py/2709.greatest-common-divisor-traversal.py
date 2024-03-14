#
# @lc app=leetcode id=2709 lang=python3
#
# [2709] Greatest Common Divisor Traversal
#

# @lc code=start

maxn = 10 ** 5 + 1
fac = [[] for _ in range(maxn)]
for i in range(2, maxn):
    if len(fac[i]) == 0:
        for j in range(i, maxn, i):
            fac[j].append(i)

class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)
        fa = [i for i in range(n + maxn)]
        def find(x: int) -> int:
            if fa[x] != x:
                fa[x] = find(fa[x])
            return fa[x]
        def union(x: int, y: int):
            fx, fy = find(x), find(y)
            if fx != fy:
                fa[fy] = fx
        
        for i in range(n):
            for p in fac[nums[i]]:
                union(i, n + p)
        res = set()
        for i in range(n):
            res.add(find(i))
            if len(res) > 1:
                return False
        return True
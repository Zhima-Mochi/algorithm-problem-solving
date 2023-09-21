#
# @lc app=leetcode id=1916 lang=python3
#
# [1916] Count Ways to Build Rooms in an Ant Colony
#
from math import comb
# @lc code=start

class Solution:
    def waysToBuildRooms(self, prevRoom: List[int]) -> int:
        MOD = 1000000007
        n = len(prevRoom)
        nextRooms = [[] for _ in range(n)]
        for i in range(1, n):
            nextRooms[prevRoom[i]].append(i)

        def dfs(room):
            res = 1
            nums = []
            for next in nextRooms[room]:
                cnt, num = dfs(next)
                res *= cnt
                res %= MOD
                nums.append(num)
            total = sum(nums)
            for n in nums:
                res *= comb(total, n)
                total -= n
                res %= MOD
            return res, sum(nums)+1
        res, _ = dfs(0)
        return res


# @lc code=end

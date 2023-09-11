#
# @lc app=leetcode id=1735 lang=python3
#
# [1735] Count Ways to Make Array With Product
#
from collections import defaultdict
from math import comb
# @lc code=start


class Solution:
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        MOD = 1000000007

        def repCombCount(n, goal):
            factors = defaultdict(int)
            i = 2
            while i * i <= goal:
                if goal % i == 0:
                    factors[i] += 1
                    goal //= i
                else:
                    i += 1
            if goal > 1:
                factors[goal] += 1

            count = 1
            for num in factors:
                count *= comb(n + factors[num] - 1, factors[num])
                count %= MOD
            return count
        return [repCombCount(q[0], q[1]) for q in queries]
# @lc code=end

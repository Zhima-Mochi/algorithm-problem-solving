#
# @lc app=leetcode id=808 lang=python3
#
# [808] Soup Servings
#

# @lc code=start
class Solution:
    def soupServings(self, n: int) -> float:
        record = [[0]*200 for _ in range(200)]
        if n >= 5000:
            return 1

        def helpler(a, b):
            b = 0 if b < 0 else b
            a = 0 if a < 0 else a
            if record[a][b] > 0:
                return record[a][b]
            if a == 0 and b == 0:
                return 0.5
            elif a == 0:
                return 1
            elif b == 0:
                return 0
            res = 0
            res += 0.25*(helpler(a - 4, b) + helpler(a - 3, b - 1) +
                         helpler(a - 2, b - 2) + helpler(a - 1, b - 3))
            record[a][b] = res
            return res
        return helpler((n+24)//25, (n+24)//25)

# @lc code=end

#
# @lc app=leetcode id=1447 lang=python3
#
# [1447] Simplified Fractions
#
import math
# @lc code=start

# t:O(n^2log(n)), s:O(n^2)
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        res = []
        for i in range(2, n+1):
            for j in range(1, i):
                if math.gcd(i, j) == 1:
                    res.append(str(j)+'/'+str(i))
        return res
# @lc code=end

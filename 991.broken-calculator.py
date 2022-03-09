#
# @lc app=leetcode id=991 lang=python3
#
# [991] Broken Calculator
#

# @lc code=start
class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        def dfs(n: int) -> int:
            if n == startValue:
                return 0
            if n % 2 == 0 and n > startValue:
                return 1 + dfs(n//2)
            elif n < startValue:
                return startValue-n
            else:
                return 1 + dfs(n+1)
        return dfs(target)
# @lc code=end

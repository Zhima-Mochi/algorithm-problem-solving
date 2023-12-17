#
# @lc app=leetcode id=1553 lang=python3
#
# [1553] Minimum Number of Days to Eat N Oranges
#

# @lc code=start
# t:O(log^2(n)) s:O(log^2(n))
class Solution:
    @cache
    def minDays(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 0:
            return 0
        ans = (1 << 31)-1
        if n % 2 == 0:
            ans = min(ans, 1+self.minDays(n//2))
        if n % 3 == 0:
            ans = min(ans, 1 + self.minDays(n//3))
        if (n-1) % 2 == 0:
            ans = min(ans, 2+self.minDays((n-1)//2))
        if (n-1) % 3 == 0:
            ans = min(ans, 2+self.minDays((n-1)//3))
        if (n-2) % 3 == 0:
            ans = min(ans, 3+self.minDays((n-2)//3))
        return ans

# @lc code=end

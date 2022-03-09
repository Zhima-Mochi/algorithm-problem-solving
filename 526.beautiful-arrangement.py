#
# @lc app=leetcode id=526 lang=python3
#
# [526] Beautiful Arrangement
#

# @lc code=start
class Solution:
    def countArrangement(self, n: int) -> int:
        self.res = 0
        self.seen = [False]*n
        self.backtrack(n)
        return self.res

    def backtrack(self, n):
        if n == 0:
            self.res += 1
            return
        for i in range(len(self.seen)):
            if not self.seen[i] and ((n % (i + 1)) == 0 or ((i + 1) % n) == 0):
                self.seen[i] = True
                self.backtrack(n-1)
                self.seen[i] = False

# @lc code=end

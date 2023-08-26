#
# @lc app=leetcode id=2002 lang=python3
#
# [2002] Maximum Product of the Length of Two Palindromic Subsequences
#

# @lc code=start
# t:O(2^n), s:O(2^n)
class Solution:
    def maxProduct(self, s: str) -> int:
        w = len(s)
        self.memo = dict()
        self.memo[0] = 0
        res = 0
        for i in range(1 << w):
            self.memo[i] = self.palindCnt(s, i)
        for i in range(1 << w):
            res = max(res, self.memo[i]*self.memo[((1 << w)-1) ^ i])
        return res

    def palindCnt(self, s, used):
        if used == 0:
            return 0
        left = 0
        right = len(s)-1
        while left <= right:
            if ((1 << left) & used) == 0:
                left += 1
            elif ((1 << right) & used) == 0:
                right -= 1
            else:
                break
        if left == right:
            return 1
        res = max(self.memo[used ^ (1 << left)],
                  self.memo[used ^ (1 << right)])
        if s[left] == s[right]:
            res = max(res, self.memo[used ^ (1 << left) ^ (1 << right)]+2)

        return res

# @lc code=end

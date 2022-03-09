#
# @lc app=leetcode id=214 lang=python3
#
# [214] Shortest Palindrome
#

# @lc code=start
# t:O(len(s)), s:O(1)
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        base = 29
        mod = 1000000007
        left = 0
        right = 0
        mp = 1
        shift = ord('a')-1
        idx = -1
        for i in range(len(s)):
            left = (left*base+(ord(s[i])-shift)) % mod
            right = (right+(ord(s[i])-shift)*mp) % mod
            if left == right:
                idx = i
            mp *= base
            mp %= mod
        return s[-1:idx:-1]+s

# @lc code=end

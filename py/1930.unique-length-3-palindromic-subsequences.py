#
# @lc app=leetcode id=1930 lang=python3
#
# [1930] Unique Length-3 Palindromic Subsequences
#
from collections import Counter
import string
# @lc code=start


class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        w = len(s)
        seen = Counter()
        records_left = [0]*w
        records_right = [0]*w
        for i in range(1, w):
            records_left[i] = records_left[i-1] | (1 << (ord(s[i-1])-ord('a')))
        for i in range(w-2, -1, -1):
            records_right[i] = records_right[i+1] | (1 << (ord(s[i+1])-ord('a')))

        for i in range(1, w-1):
            seen[s[i]] |= records_left[i] & records_right[i]
        res = 0
        for a in seen:
            while seen[a]:
                if seen[a] & 1:
                    res += 1
                seen[a] >>= 1
        return res
# @lc code=end

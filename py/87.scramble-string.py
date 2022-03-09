#
# @lc app=leetcode id=87 lang=python3
#
# [87] Scramble String
#

from typing import Counter
from collections import Counter
# @lc code=start

# t:O(n^4), s:O(n^3)
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        w = len(s1)
        records = Counter()

        def dp(left1, left2, width):
            if width == 1:
                return s1[left1] == s2[left2]
            key = left1 * 1024 + left2 * 32 + width
            if key in records:
                return records[key]
            if Counter(s1[left1:left1+width]) != Counter(s2[left2:left2+width]):
                records[key] = False
                return records[key]
            s1_count = Counter()
            s2_count = Counter()
            for i in range(width-1):
                s1_count[s1[left1+i]] += 1
                s2_count[s2[left2+i]] += 1
                if s1_count == s2_count:
                    if dp(left1, left2, i+1) and dp(left1+i+1, left2+i+1, width-i-1):
                        records[key] = True
                        return records[key]
            s1_count = Counter()
            s2_count = Counter()
            for i in range(width-1):
                s1_count[s1[left1+i]] += 1
                s2_count[s2[left2+width-1-i]] += 1
                if s1_count == s2_count:
                    if dp(left1, left2+width-1-i, i+1) and dp(left1+i+1, left2, width-i-1):
                        records[key] = True
                        return records[key]
            records[key] = False
            return records[key]
        return dp(0, 0, w)

# @lc code=end

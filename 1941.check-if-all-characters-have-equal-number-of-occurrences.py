#
# @lc app=leetcode id=1941 lang=python3
#
# [1941] Check if All Characters Have Equal Number of Occurrences
#
from collections import Counter
# @lc code=start


class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        stat = Counter()
        for c in s:
            stat[c] += 1
        num = next(iter(stat.values()))
        for val in stat.values():
            if val != num:
                return False
        return True
# @lc code=end

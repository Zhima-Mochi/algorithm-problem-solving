#
# @lc app=leetcode id=524 lang=python3
#
# [524] Longest Word in Dictionary through Deleting
#
from typing import*
# @lc code=start


class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        dictionary.sort(key=lambda elem: (-len(elem), elem))
        for comp_str in dictionary:
            if self.isSubstring(s, comp_str):
                return comp_str
        return ""

    def isSubstring(self, s: str, comp_str: str):
        if len(s) < len(comp_str):
            return False
        pos = 0
        for c in comp_str:
            next_pos = s.find(c, pos)
            if next_pos == -1:
                return False
            pos = next_pos+1
        return True

# @lc code=end

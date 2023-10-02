#
# @lc app=leetcode id=828 lang=python3
#
# [828] Count Unique Characters of All Substrings of a Given String
#
import string
# @lc code=start
# t:O(n), s:O(1)


class Solution:
    def uniqueLetterString(self, s: str) -> int:
        n = len(s)
        last_seen = dict()
        last_2_seen = dict()
        res = 0
        for c in string.ascii_uppercase:
            last_2_seen[c] = -1
            last_seen[c] = -1
        prev = 0
        for i in range(n):
            prev -= last_seen[s[i]]-last_2_seen[s[i]]
            last_2_seen[s[i]] = last_seen[s[i]]
            last_seen[s[i]] = i
            prev += last_seen[s[i]]-last_2_seen[s[i]]
            res += prev
        return res

# @lc code=end

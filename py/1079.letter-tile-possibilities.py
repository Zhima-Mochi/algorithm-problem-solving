#
# @lc app=leetcode id=1079 lang=python3
#
# [1079] Letter Tile Possibilities
#

# @lc code=start
from typing import List

# t:O(N!), s:O(N)
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        rest = [0]*26
        for c in tiles:
            rest[ord(c)-ord('A')] += 1

        def dp(rest: List):
            res = 0
            for i in range(26):
                if rest[i]:
                    rest[i] -= 1
                    res += 1
                    res += dp(rest)
                    rest[i] += 1
            return res
        return dp(rest)


# @lc code=end

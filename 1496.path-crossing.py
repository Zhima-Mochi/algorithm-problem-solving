#
# @lc app=leetcode id=1496 lang=python3
#
# [1496] Path Crossing
#

# @lc code=start
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        pos = 0
        seen = {0}
        for c in path:
            if c == 'N':
                pos += 1
            elif c == 'S':
                pos -= 1
            elif c == 'E':
                pos += 1 << 14
            else:
                pos -= 1 << 14
            if pos in seen:
                return True
            else:
                seen.add(pos)
        return False
# @lc code=end

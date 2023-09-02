#
# @lc app=leetcode id=2511 lang=python3
#
# [2511] Maximum Enemy Forts That Can Be Captured
#

# @lc code=start
# t:O(n), s:O(1)
class Solution:
    def captureForts(self, forts: List[int]) -> int:
        cur = 1
        w = len(forts)
        prev = 0
        res = 0
        while cur < w:
            if forts[cur] != 0:
                if forts[prev]+forts[cur] == 0:
                    res = max(res, cur-prev-1)
                prev = cur
            cur += 1
        return res


# @lc code=end

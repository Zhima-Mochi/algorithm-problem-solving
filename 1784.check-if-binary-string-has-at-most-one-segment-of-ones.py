#
# @lc app=leetcode id=1784 lang=python3
#
# [1784] Check if Binary String Has at Most One Segment of Ones
#

# @lc code=start
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        cnt = 0
        prev = '0'
        for c in s:
            if prev == '0' and c == '1':
                cnt += 1
                if cnt == 2:
                    return False
            prev = c
        return cnt == 1
# @lc code=end

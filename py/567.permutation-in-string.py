#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#

# @lc code=start
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        window_len = len(s1)
        s2_len = len(s2)
        if window_len > s2_len:
            return False
        stat = [0]*26
        all_zero = [0]*26
        for c in s1:
            stat[ord(c)-ord('a')] -= 1
        for i in range(window_len):
            stat[ord(s2[i])-ord('a')] += 1
        if stat == all_zero:
            return True
        for i in range(window_len, s2_len):
            stat[ord(s2[i])-ord('a')] += 1
            stat[ord(s2[i-window_len])-ord('a')] -= 1
            if stat == all_zero:
                return True
        return False
# @lc code=end

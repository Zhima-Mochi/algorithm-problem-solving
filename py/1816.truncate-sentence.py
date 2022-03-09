#
# @lc app=leetcode id=1816 lang=python3
#
# [1816] Truncate Sentence
#

# @lc code=start
class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        ind = 0
        while k:
            k = k-1
            ind = s.find(' ', ind)
            if ind != -1:
                if k:
                    ind += 1
            else:
                ind = len(s)
                break
        return s[0:ind]
# @lc code=end

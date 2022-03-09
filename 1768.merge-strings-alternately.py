#
# @lc app=leetcode id=1768 lang=python3
#
# [1768] Merge Strings Alternately
#

# @lc code=start
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        w1_w = len(word1)
        w2_w = len(word2)
        min_w = min(w1_w, w2_w)
        res = [None]*(min_w*2)
        for i in range(min_w):
            res[2*i] = word1[i]
            res[2*i+1] = word2[i]
        if w1_w > min_w:
            return ''.join(res)+word1[min_w:]
        elif w2_w > min_w:
            return ''.join(res)+word2[min_w:]
        else:
            return ''.join(res)

# @lc code=end

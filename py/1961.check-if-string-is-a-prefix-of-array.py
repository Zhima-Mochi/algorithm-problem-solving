#
# @lc app=leetcode id=1961 lang=python3
#
# [1961] Check If String Is a Prefix of Array
#

# @lc code=start
class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        width = len(s)
        ind = 0
        for word in words:
            for c in word:
                if ind == width or c != s[ind]:
                    return False
                else:
                    ind += 1
            if ind == width:
                return True
        return False
# @lc code=end

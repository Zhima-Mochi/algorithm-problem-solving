#
# @lc app=leetcode id=1790 lang=python3
#
# [1790] Check if One String Swap Can Make Strings Equal
#

# @lc code=start
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        diff_ind = []
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                if len(diff_ind) == 2:
                    return False
                diff_ind.append(i)
        if len(diff_ind) == 0:
            return True
        elif len(diff_ind) == 1:
            return False
        else:
            return s1[diff_ind[0]] == s2[diff_ind[1]] and s1[diff_ind[1]] == s2[diff_ind[0]]

# @lc code=end

#
# @lc app=leetcode id=1003 lang=python3
#
# [1003] Check If Word Is Valid After Substitutions
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c == 'b':
                if len(st) == 0 or st[-1] != 'a':
                    return False
                st.append(c)
            if c == 'c':
                if len(st) < 2 or st[-2:] != ['a', 'b']:
                    return False
                st.pop()
                st.pop()
            if c == 'a':
                st.append(c)
        return len(st) == 0


# @lc code=end

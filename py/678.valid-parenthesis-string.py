#
# @lc app=leetcode id=678 lang=python3
#
# [678] Valid Parenthesis String
#

# @lc code=start
class Solution:
    def checkValidString(self, s: str) -> bool:
        muteki_symbol = 0
        trans_to_left_symbol = 0
        rest_min_left = 0
        for c in s:
            if c == '(':
                rest_min_left += 1
            elif c == ')':
                if rest_min_left > 0:
                    rest_min_left -= 1
                elif muteki_symbol > 0:
                    muteki_symbol -= 1
                elif trans_to_left_symbol > 0:
                    trans_to_left_symbol -= 1
                    muteki_symbol += 1
                else:
                    return False
            else:
                if rest_min_left > 0:
                    rest_min_left -= 1
                    trans_to_left_symbol += 1
                else:
                    muteki_symbol += 1
        return rest_min_left == 0
# @lc code=end

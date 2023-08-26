#
# @lc app=leetcode id=2337 lang=python3
#
# [2337] Move Pieces to Obtain a String
#

# @lc code=start
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        w = len(start)
        left = 0
        right = 0
        while right != w and left != w:
            if start[left] == '_':
                left += 1
            elif target[right] == '_':
                right += 1
            elif start[left] != target[right]:
                return False
            elif start[left] == 'L' and right > left:
                return False
            elif start[left] == 'R' and right < left:
                return False
            else:
                left += 1
                right += 1
        while left != w:
            if start[left] != '_':
                return False
            left += 1
        while right != w:
            if target[right] != '_':
                return False
            right += 1
        return True

# @lc code=end

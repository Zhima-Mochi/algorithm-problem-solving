#
# @lc app=leetcode id=789 lang=python3
#
# [789] Escape The Ghosts
#

# @lc code=start
class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        distance = abs(target[0])+abs(target[1])
        for ghost in ghosts:
            if abs(ghost[0]-target[0])+abs(ghost[1]-target[1]) <= distance:
                return False
        return True
# @lc code=end

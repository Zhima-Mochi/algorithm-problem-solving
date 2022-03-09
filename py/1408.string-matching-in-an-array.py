#
# @lc app=leetcode id=1408 lang=python3
#
# [1408] String Matching in an Array
#

# @lc code=start
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        return [s for s in words if any(True for i in words if i != s and s in i)]


# @lc code=end

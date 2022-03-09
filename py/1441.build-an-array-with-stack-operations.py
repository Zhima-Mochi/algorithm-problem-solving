#
# @lc app=leetcode id=1441 lang=python3
#
# [1441] Build an Array With Stack Operations
#

# @lc code=start
class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        value = 1
        res = []
        for n in target:
            res.extend(["Push", "Pop"]*(n-value))
            res.append("Push")
            value = n+1
        return res
# @lc code=end

#
# @lc app=leetcode id=1436 lang=python3
#
# [1436] Destination City
#

# @lc code=start
import collections


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        depart_place = {pr[0] for pr in paths}
        for pr in paths:
            if not pr[1] in depart_place:
                return pr[1]
        return ""
# @lc code=end

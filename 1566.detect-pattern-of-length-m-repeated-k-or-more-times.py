#
# @lc app=leetcode id=1566 lang=python3
#
# [1566] Detect Pattern of Length M Repeated K or More Times
#

# @lc code=start
class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        dp = m
        for i in range(m, len(arr)):
            if arr[i] == arr[i-m]:
                dp += 1
                if dp == k*m:
                    return True
            else:
                dp = m
        return False
# @lc code=end

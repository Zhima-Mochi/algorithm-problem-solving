#
# @lc app=leetcode id=1437 lang=python3
#
# [1437] Check If All 1's Are at Least Length K Places Away
#

# @lc code=start
class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        if k == 0:
            return True
        distance = 0
        for n in nums:
            if n == 0:
                distance += 1
            else:
                if distance < 0:
                    return False
                else:
                    distance = -k
        return True
# @lc code=end

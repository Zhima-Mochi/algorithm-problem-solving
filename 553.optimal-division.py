#
# @lc app=leetcode id=553 lang=python3
#
# [553] Optimal Division
#

# @lc code=start
class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        width = len(nums)
        if width == 1:
            return str(nums[0])
        elif width == 2:
            return str(nums[0])+'/'+str(nums[1])
        res = []
        res.append(str(nums[0]))
        res.append("/(")
        for i in range(1, width-1):
            res.append(str(nums[i]))
            res.append('/')
        res.append(str(nums[width-1]))
        res.append(')')
        return ''.join(res)

# @lc code=end

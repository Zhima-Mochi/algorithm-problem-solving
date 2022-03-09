#
# @lc app=leetcode id=1460 lang=python3
#
# [1460] Make Two Arrays Equal by Reversing Sub-arrays
#

# @lc code=start
class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        target.sort(), arr.sort()
        return target == arr
# @lc code=end

# class Solution:
#     def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
#         count = [0]*1001
#         for n in target:
#             count[n] += 1
#         for n in arr:
#             if count[n] == 0:
#                 return False
#             count[n] -= 1
#         return True

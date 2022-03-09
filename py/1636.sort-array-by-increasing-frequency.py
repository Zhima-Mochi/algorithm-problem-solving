#
# @lc app=leetcode id=1636 lang=python3
#
# [1636] Sort Array by Increasing Frequency
#

# @lc code=start
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq = [0]*201
        for n in nums:
            freq[n+100] += 1
        nums.sort(key=lambda x: (freq[x+100] << 10)-x)
        return nums
# @lc code=end

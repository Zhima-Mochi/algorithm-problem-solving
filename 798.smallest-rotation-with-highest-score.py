#
# @lc app=leetcode id=798 lang=python3
#
# [798] Smallest Rotation with Highest Score
#

# @lc code=start
# t:O(N), s:O(N)
class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        w = len(nums)
        high_points = 0
        diff_count = [0]*w
        res = 0
        for i in range(w):
            if nums[i] <= i:
                high_points += 1
            else:
                diff_count[nums[i]-i] += 1
        points = high_points
        for i in range(w-1, 0, -1):
            if nums[i] <= w-1:
                points -= 1
            index = w-1-i+1+nums[i]
            if index < w:
                diff_count[index] += 1
            points += diff_count[w-1-i+1]
            if points == high_points:
                if res != 0:
                    res = i
            elif points > high_points:
                high_points = points
                res = i
        return res
# @lc code=end

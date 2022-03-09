#
# @lc app=leetcode id=1035 lang=python3
#
# [1035] Uncrossed Lines
#

# @lc code=start
# t:O(MN), s:O(N)
class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        w1 = len(nums1)
        w2 = len(nums2)
        dp = [0]*(w2+1)
        for i in range(w1):
            prev_val = dp[0]
            for j in range(w2):
                next_prev_val = dp[j+1]
                if nums1[i] == nums2[j]:
                    dp[j+1] = max(dp[j+1], dp[j], prev_val+1)
                else:
                    dp[j+1] = max(dp[j+1], dp[j])
                prev_val = next_prev_val
        return dp[w2]
# @lc code=end

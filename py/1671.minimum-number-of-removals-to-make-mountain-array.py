#
# @lc app=leetcode id=1671 lang=python3
#
# [1671] Minimum Number of Removals to Make Mountain Array
#

# @lc code=start
class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        dp1 = list(range(n))
        dp2 = list(range(n-1,-1,-1))
        for i in range(1, n):
            for j in range(i-1,-1,-1):
                if nums[i]>nums[j]:
                    dp1[i] = min(dp1[i], dp1[j]+i-j-1)
        for i in range(n-2, -1, -1):
            for j in range(i+1,n):
                if nums[i]>nums[j]:
                    dp2[i] = min(dp2[i], dp2[j]+j-i-1)
        ans = n
        for i in range(1, n-1):
            if dp1[i]!=i and dp2[i]!=n-1-i:
                ans = min(ans, dp1[i]+dp2[i])
        return ans
# @lc code=end

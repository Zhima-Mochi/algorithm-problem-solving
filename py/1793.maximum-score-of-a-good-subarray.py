#
# @lc app=leetcode id=1793 lang=python3
#
# [1793] Maximum Score of a Good Subarray
#

# @lc code=start
# t:O(n), s:O(n)
class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        stk = []
        n = len(nums)
        res = min(nums)*n
        cur_min = nums[k]
        for i in range(n):
            if i < k:
                while len(stk) and nums[stk[-1]] >= nums[i]:
                    stk.pop()
                stk.append(i)
            elif i == k:
                while len(stk) and nums[stk[-1]] >= nums[i]:
                    stk.pop()
                pt = stk[-1] if len(stk) else -1
                res = max(res, cur_min*(i-pt))
                stk.append(i)
            else:
                cur_min = min(cur_min, nums[i])
                while len(stk) and nums[stk[-1]] >= cur_min:
                    id = stk.pop()
                    pt = stk[-1] if len(stk) else -1
                    res = max(res, nums[id]*(i-pt-1))
                pt = stk[-1] if len(stk) else -1
                res = max(res, cur_min*(i-pt))
        while len(stk):
            cur_min = nums[stk.pop()]
            pt = stk[-1] if len(stk) else -1
            res = max(res, cur_min*(n-1-pt))
        return res


# @lc code=end

#
# @lc app=leetcode id=525 lang=python3
#
# [525] Contiguous Array
#

# @lc code=start
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        # key: sum_val value: index
        umap = {}
        res = 0
        umap[0] = -1
        sum_val = 0
        index = 0
        for n in nums:
            if n == 0:
                sum_val -= 1
            else:
                sum_val += 1
            if sum_val in umap:
                res = max(res, index-umap[sum_val])
            else:
                u = umap[sum_val] = index
            index += 1
        return res
# @lc code=end

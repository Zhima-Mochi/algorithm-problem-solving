#
# @lc app=leetcode id=969 lang=python3
#
# [969] Pancake Sorting
#

# @lc code=start
class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        w = len(arr)
        bucket_sort = [None]*w
        for i in range(w):
            bucket_sort[w-arr[i]] = i+1
        res = []
        for n in bucket_sort:
            for m in res:
                if n <= m:
                    n = m-n+1
            res.append(n)
            res.append(w)
            w -= 1
        return res

# @lc code=end

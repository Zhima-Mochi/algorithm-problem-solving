#
# @lc app=leetcode id=1326 lang=python3
#
# [1326] Minimum Number of Taps to Open to Water a Garden
#

# @lc code=start

# t:O(nlog(n)), s:O(n)
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        covers = []
        for i in range(n+1):
            if ranges[i] > 0:
                covers.append([i-ranges[i], i+ranges[i]])
        covers.sort()
        res = 0
        dist = 0
        cur_far = 0
        if len(covers) == 0 or covers[0][0] > 0:
            return -1
        for cover in covers:
            if cover[0] <= dist:
                cur_far = max(cur_far, cover[1])
            elif cur_far < cover[0]:
                return -1
            else:
                res += 1
                dist = cur_far
                cur_far = cover[1]
                if dist >= n:
                    return res
            if cur_far >= n:
                return res+1
            elif dist >= n:
                return res
        return -1

# @lc code=end

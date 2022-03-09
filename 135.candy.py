#
# @lc app=leetcode id=135 lang=python3
#
# [135] Candy
#

# @lc code=start
class Solution:
    def candy(self, ratings: List[int]) -> int:
        w = len(ratings)
        get_candy = [1]*w
        for i in range(1, w):
            if ratings[i] > ratings[i-1]:
                get_candy[i] = get_candy[i-1]+1
        res = get_candy[-1]
        for i in range(w-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                get_candy[i]=max(get_candy[i], get_candy[i+1]+1)
            res += get_candy[i]
        return res
# @lc code=end

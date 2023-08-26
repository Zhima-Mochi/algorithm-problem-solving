#
# @lc app=leetcode id=1997 lang=python3
#
# [1997] First Day Where You Have Been in All the Rooms
#

# @lc code=start
# t:O(n), s:O(n)
class Solution:
    MOD = 1000000007

    def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
        w = len(nextVisit)
        accum = [0]*(w+1)
        for i in range(w-1):
            temp=0
            temp += accum[i]-accum[nextVisit[i]]+(i-nextVisit[i])
            temp += 1
            temp += self.MOD
            temp %= self.MOD
            accum[i+1] = accum[i]+temp
        return (accum[w-1]+w-1) % self.MOD


# @lc code=end

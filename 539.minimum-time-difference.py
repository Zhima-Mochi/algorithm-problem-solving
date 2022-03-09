#
# @lc app=leetcode id=539 lang=python3
#
# [539] Minimum Time Difference
#

# @lc code=start
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        time_seen = [False]*60*24
        for time in timePoints:
            h = int(time[0:2])
            m = int(time[3:5])
            if time_seen[60*h+m]:
                return 0
            else:
                time_seen[60*h+m] = True
        pos_first = 0
        while not time_seen[pos_first]:
            pos_first += 1
        pos_last = 60*24-1
        while not time_seen[pos_last]:
            pos_last -= 1
        res = pos_first - pos_last + 60 * 24
        if res == 1:
            return 1
        count = 1
        print(m)
        for i in range(pos_first+1, pos_last+1):
            if time_seen[i]:
                res = min(res, count)
                if res == 1:
                    return 1
                count = 1
            else:
                count += 1
        return res


# @lc code=end
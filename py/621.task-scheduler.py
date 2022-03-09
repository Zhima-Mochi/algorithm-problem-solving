#
# @lc app=leetcode id=621 lang=python3
#
# [621] Task Scheduler
#

# @lc code=start
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        if n == 0:
            return len(tasks)
        seen_count = [0]*26
        for c in tasks:
            seen_count[ord(c)-ord('A')] += 1
        max_count = max(seen_count)
        return max(len(tasks), (max_count-1)*(n+1)+seen_count.count(max_count))
# @lc code=end

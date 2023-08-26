#
# @lc app=leetcode id=1986 lang=python3
#
# [1986] Minimum Number of Work Sessions to Finish the Tasks
#
import heapq
# @lc code=start


class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        self.tasks = tasks
        self.sessionTime = sessionTime
        self.memo = [-1]*(1 << len(tasks))
        return self.dfs((1 << len(tasks))-1, 0)

    def dfs(self, left_tasks, capacity):
        if left_tasks == 0:
            return 0
        if capacity == self.sessionTime and self.memo[left_tasks] != -1:
            return self.memo[left_tasks]
        res = (1 << 31)-1
        picked = set()
        for i in range(len(self.tasks)):
            if ((1 << i) & left_tasks) and self.tasks[i] <= capacity:
                if (self.tasks[i] in picked):
                    continue
                picked.add(self.tasks[i])

                res = min(res, self.dfs(left_tasks ^ (1 << i),
                          capacity-self.tasks[i]))
        if res == (1 << 31)-1:
            res = 1+self.dfs(left_tasks, self.sessionTime)
        if capacity == self.sessionTime:
            self.memo[left_tasks] = res
        return res


# @lc code=end

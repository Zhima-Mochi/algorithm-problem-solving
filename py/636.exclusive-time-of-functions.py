#
# @lc app=leetcode id=636 lang=python3
#
# [636] Exclusive Time of Functions
#
from typing import *
# @lc code=start


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        tasks_stack = []
        tasks_exc_time = [0]*n
        run_time = 0
        for log in logs:
            task_num = int(log[0:log.find(':')])
            time_num = int(log[log.rfind(':')+1:])
            status = log[log.find(':')+1:log.rfind(':')]
            if status == "start":
                if len(tasks_stack):
                    tasks_exc_time[tasks_stack[-1]] += time_num-run_time
                tasks_stack.append(task_num)
                run_time = time_num
            else:
                tasks_exc_time[task_num] += time_num - run_time + 1
                tasks_stack.pop()
                run_time = time_num + 1
        return tasks_exc_time
# @lc code=end

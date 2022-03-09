#
# @lc app=leetcode id=743 lang=python3
#
# [743] Network Delay Time
#
import heapq
# @lc code=start


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        node_connection = [[] for _ in range(n+1)]
        for time in times:
            node_connection[time[0]].append([time[1], time[2]])
        shortest_time = [-1]*(n+1)
        shortest_time[0] = 0
        shortest_time_queue = [(0, k)]
        while shortest_time_queue:
            node_time, node_num = heapq.heappop(shortest_time_queue)
            if shortest_time[node_num] != -1:
                continue
            shortest_time[node_num] = node_time
            for time in node_connection[node_num]:
                # time[0]: node, time[1]: time
                if shortest_time[time[0]] == -1:
                    heapq.heappush(shortest_time_queue,
                                   ([node_time+time[1], time[0]]))
        res = 0
        for n in shortest_time:
            if n == -1:
                return -1
            else:
                res = max(res, n)
        return res

# @lc code=end

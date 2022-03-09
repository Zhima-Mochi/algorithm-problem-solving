/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> node_connection(n + 1);
        for (auto &time : times)
        {
            node_connection[time[0]].push_back({time[1], time[2]});
        }
        vector<int> shortest_time(n + 1, -1);
        shortest_time[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> shortest_time_queue;
        shortest_time_queue.push({0, k});
        while (!shortest_time_queue.empty())
        {
            int node_num = shortest_time_queue.top().second;
            int node_time = shortest_time_queue.top().first;
            shortest_time_queue.pop();
            if (shortest_time[node_num] != -1)
            {
                continue;
            }
            shortest_time[node_num] = node_time;
            for (auto &p : node_connection[node_num])
            {
                // first: node, second: time
                if (shortest_time[p.first] == -1)
                {
                    shortest_time_queue.push({node_time + p.second, p.first});
                }
            }
        }
        int res = 0;
        for (auto n : shortest_time)
        {
            if (n == -1)
            {
                return -1;
            }
            else
            {
                res = max(res, n);
            }
        }
        return res;
    }
};
// @lc code=end

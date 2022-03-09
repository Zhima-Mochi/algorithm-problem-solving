/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(V+E), s:O(V+E)
class Solution
{
    int time = 0;

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, vector<int>> connect;
        for (auto &con : connections)
        {
            connect[con[0]].push_back(con[1]);
            connect[con[1]].push_back(con[0]);
        }
        vector<int> parent(n, -1);
        vector<int> seen_time(n, -1);
        vector<int> lowest(n);
        vector<vector<int>> res;
        function<void(int)> findBridge = [&](int node)
        {
            seen_time[node] = ++time;
            lowest[node] = time;
            for (auto child : connect[node])
            {
                if (seen_time[child] == -1)
                {
                    parent[child] = node;
                    findBridge(child);
                    lowest[node] = min(lowest[node], lowest[child]);
                    if (lowest[child] > seen_time[node])
                    {
                        res.push_back({node, child});
                    }
                }
                else if (child != parent[node])
                {
                    lowest[node] = min(lowest[node], seen_time[child]);
                }
            }
        };
        for (int i = 0; i != n; ++i)
        {
            if (seen_time[i] == -1)
            {
                findBridge(i);
            }
        }
        return res;
    }
};
// @lc code=end

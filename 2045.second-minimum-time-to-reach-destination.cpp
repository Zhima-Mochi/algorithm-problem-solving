/*
 * @lc app=leetcode id=2045 lang=cpp
 *
 * [2045] Second Minimum Time to Reach Destination
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(n+len(edges)), s:O(n+len(edges))
class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<int> seen_times(n + 1);
        vector<vector<int>> vertex_map(n + 1);
        for (auto &edge : edges)
        {
            vertex_map[edge[0]].push_back(edge[1]);
            vertex_map[edge[1]].push_back(edge[0]);
        }
        int res = -1;
        int total_time = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            if (total_time / change % 2)
            {
                total_time = change * (total_time / change + 1);
            }
            total_time += time;
            int q_len = q.size();
            vector<bool> this_turn_seen(n + 1);
            while (q_len--)
            {
                int pt = q.front();
                q.pop();
                for (auto next : vertex_map[pt])
                {
                    if (next == n)
                    {
                        if (res == -1)
                        {
                            res = total_time;
                        }
                        else if (total_time > res)
                        {
                            return total_time;
                        }
                    }
                    if (!this_turn_seen[next] && seen_times[next] <= 1)
                    {
                        q.push(next);
                        ++seen_times[next];
                        this_turn_seen[next] = true;
                    }
                }
            }
        }
        // if (total_time / change % 2)
        // {
        //     total_time = change * (total_time / change + 1);
        // }
        // total_time += time;
        // if (total_time / change % 2)
        // {
        //     total_time = change * (total_time / change + 1);
        // }
        // total_time += time;
        return total_time;
    }
};
// @lc code=end
